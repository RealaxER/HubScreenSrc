use clap::Parser;
use system_intergration::SystemIntergration;
pub mod error;
pub mod master;
pub mod logic;
pub mod proto;
pub mod system_intergration;
pub mod transport;
pub mod timer;
pub mod sqlite;

use std::time::Duration;
use std::thread::sleep;

#[derive(Debug, Parser)]
#[command(author, version, about, long_about = None)]
struct Args {
    #[clap(short, long)]
    mac: String,
}


#[tokio::main]
async fn main() {
    env_logger::builder().format_timestamp_millis().init();

    let args = Args::parse();
    log::info!("args: {:?}", args);

    let mut nw_check = logic::BrLogic::new();
    loop {
        match nw_check.get_local_ip() {
            Ok(ip) => {
                log::info!("Local IP address: {}", ip);
                break;
            }
            Err(e) => {
                log::info!("Error: {:?}", e);
                log::info!("Retrying in 5 seconds...");
                sleep(Duration::from_secs(5)); // Đợi 5 giây trước khi thử lại
            }
        }
    }
    let mut system_intergration = SystemIntergration::new(args.mac).await;
    system_intergration.init().await;

    loop {
        match system_intergration.recv().await {
            Ok(_) => {}
            Err(e) => {
                log::error!("{:?}", e);
                break;
            }
        }
    }
}
