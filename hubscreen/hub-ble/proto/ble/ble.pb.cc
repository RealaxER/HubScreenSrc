// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ble.proto

#include "ble.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_ble_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_ble_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_SwBle_t;
}  // namespace protobuf_ble_2eproto
class Ble_tDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Ble_t>
      _instance;
} _Ble_t_default_instance_;
class SwBle_tDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<SwBle_t>
      _instance;
} _SwBle_t_default_instance_;
namespace protobuf_ble_2eproto {
static void InitDefaultsBle_t() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Ble_t_default_instance_;
    new (ptr) ::Ble_t();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Ble_t::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_Ble_t =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsBle_t}, {
      &protobuf_ble_2eproto::scc_info_SwBle_t.base,}};

static void InitDefaultsSwBle_t() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_SwBle_t_default_instance_;
    new (ptr) ::SwBle_t();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::SwBle_t::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_SwBle_t =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsSwBle_t}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Ble_t.base);
  ::google::protobuf::internal::InitSCC(&scc_info_SwBle_t.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Ble_t, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Ble_t, sw_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Ble_t, sync_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SwBle_t, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SwBle_t, deviceid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SwBle_t, endpoint_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SwBle_t, status_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Ble_t)},
  { 7, -1, sizeof(::SwBle_t)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_Ble_t_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::_SwBle_t_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "ble.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\tble.proto\"+\n\005Ble_t\022\024\n\002sw\030\001 \001(\0132\010.SwBle"
      "_t\022\014\n\004sync\030\002 \001(\010\"=\n\007SwBle_t\022\020\n\010deviceID\030"
      "\017 \001(\r\022\020\n\010endpoint\030\020 \001(\r\022\016\n\006status\030\021 \001(\010b"
      "\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 127);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ble.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_ble_2eproto

// ===================================================================

void Ble_t::InitAsDefaultInstance() {
  ::_Ble_t_default_instance_._instance.get_mutable()->sw_ = const_cast< ::SwBle_t*>(
      ::SwBle_t::internal_default_instance());
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Ble_t::kSwFieldNumber;
const int Ble_t::kSyncFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Ble_t::Ble_t()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_ble_2eproto::scc_info_Ble_t.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:Ble_t)
}
Ble_t::Ble_t(const Ble_t& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_sw()) {
    sw_ = new ::SwBle_t(*from.sw_);
  } else {
    sw_ = NULL;
  }
  sync_ = from.sync_;
  // @@protoc_insertion_point(copy_constructor:Ble_t)
}

void Ble_t::SharedCtor() {
  ::memset(&sw_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&sync_) -
      reinterpret_cast<char*>(&sw_)) + sizeof(sync_));
}

Ble_t::~Ble_t() {
  // @@protoc_insertion_point(destructor:Ble_t)
  SharedDtor();
}

void Ble_t::SharedDtor() {
  if (this != internal_default_instance()) delete sw_;
}

void Ble_t::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Ble_t::descriptor() {
  ::protobuf_ble_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_ble_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Ble_t& Ble_t::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_ble_2eproto::scc_info_Ble_t.base);
  return *internal_default_instance();
}


void Ble_t::Clear() {
// @@protoc_insertion_point(message_clear_start:Ble_t)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaNoVirtual() == NULL && sw_ != NULL) {
    delete sw_;
  }
  sw_ = NULL;
  sync_ = false;
  _internal_metadata_.Clear();
}

bool Ble_t::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Ble_t)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .SwBle_t sw = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_sw()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool sync = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &sync_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Ble_t)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Ble_t)
  return false;
#undef DO_
}

void Ble_t::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Ble_t)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .SwBle_t sw = 1;
  if (this->has_sw()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->_internal_sw(), output);
  }

  // bool sync = 2;
  if (this->sync() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->sync(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:Ble_t)
}

::google::protobuf::uint8* Ble_t::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Ble_t)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .SwBle_t sw = 1;
  if (this->has_sw()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->_internal_sw(), deterministic, target);
  }

  // bool sync = 2;
  if (this->sync() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->sync(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Ble_t)
  return target;
}

size_t Ble_t::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Ble_t)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // .SwBle_t sw = 1;
  if (this->has_sw()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *sw_);
  }

  // bool sync = 2;
  if (this->sync() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Ble_t::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Ble_t)
  GOOGLE_DCHECK_NE(&from, this);
  const Ble_t* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Ble_t>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Ble_t)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Ble_t)
    MergeFrom(*source);
  }
}

void Ble_t::MergeFrom(const Ble_t& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Ble_t)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_sw()) {
    mutable_sw()->::SwBle_t::MergeFrom(from.sw());
  }
  if (from.sync() != 0) {
    set_sync(from.sync());
  }
}

void Ble_t::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Ble_t)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Ble_t::CopyFrom(const Ble_t& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Ble_t)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Ble_t::IsInitialized() const {
  return true;
}

void Ble_t::Swap(Ble_t* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Ble_t::InternalSwap(Ble_t* other) {
  using std::swap;
  swap(sw_, other->sw_);
  swap(sync_, other->sync_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Ble_t::GetMetadata() const {
  protobuf_ble_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_ble_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void SwBle_t::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SwBle_t::kDeviceIDFieldNumber;
const int SwBle_t::kEndpointFieldNumber;
const int SwBle_t::kStatusFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SwBle_t::SwBle_t()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_ble_2eproto::scc_info_SwBle_t.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:SwBle_t)
}
SwBle_t::SwBle_t(const SwBle_t& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&status_, &from.status_,
    static_cast<size_t>(reinterpret_cast<char*>(&endpoint_) -
    reinterpret_cast<char*>(&status_)) + sizeof(endpoint_));
  // @@protoc_insertion_point(copy_constructor:SwBle_t)
}

void SwBle_t::SharedCtor() {
  ::memset(&status_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&endpoint_) -
      reinterpret_cast<char*>(&status_)) + sizeof(endpoint_));
}

SwBle_t::~SwBle_t() {
  // @@protoc_insertion_point(destructor:SwBle_t)
  SharedDtor();
}

void SwBle_t::SharedDtor() {
}

void SwBle_t::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* SwBle_t::descriptor() {
  ::protobuf_ble_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_ble_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const SwBle_t& SwBle_t::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_ble_2eproto::scc_info_SwBle_t.base);
  return *internal_default_instance();
}


void SwBle_t::Clear() {
// @@protoc_insertion_point(message_clear_start:SwBle_t)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&status_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&endpoint_) -
      reinterpret_cast<char*>(&status_)) + sizeof(endpoint_));
  _internal_metadata_.Clear();
}

bool SwBle_t::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SwBle_t)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(16383u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // uint32 deviceID = 15;
      case 15: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(120u /* 120 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &deviceid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 endpoint = 16;
      case 16: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(128u /* 128 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &endpoint_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool status = 17;
      case 17: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(136u /* 136 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &status_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SwBle_t)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SwBle_t)
  return false;
#undef DO_
}

void SwBle_t::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SwBle_t)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 deviceID = 15;
  if (this->deviceid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(15, this->deviceid(), output);
  }

  // uint32 endpoint = 16;
  if (this->endpoint() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(16, this->endpoint(), output);
  }

  // bool status = 17;
  if (this->status() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(17, this->status(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:SwBle_t)
}

::google::protobuf::uint8* SwBle_t::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:SwBle_t)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 deviceID = 15;
  if (this->deviceid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(15, this->deviceid(), target);
  }

  // uint32 endpoint = 16;
  if (this->endpoint() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(16, this->endpoint(), target);
  }

  // bool status = 17;
  if (this->status() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(17, this->status(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SwBle_t)
  return target;
}

size_t SwBle_t::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:SwBle_t)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // bool status = 17;
  if (this->status() != 0) {
    total_size += 2 + 1;
  }

  // uint32 deviceID = 15;
  if (this->deviceid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->deviceid());
  }

  // uint32 endpoint = 16;
  if (this->endpoint() != 0) {
    total_size += 2 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->endpoint());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SwBle_t::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:SwBle_t)
  GOOGLE_DCHECK_NE(&from, this);
  const SwBle_t* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const SwBle_t>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:SwBle_t)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:SwBle_t)
    MergeFrom(*source);
  }
}

void SwBle_t::MergeFrom(const SwBle_t& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:SwBle_t)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.status() != 0) {
    set_status(from.status());
  }
  if (from.deviceid() != 0) {
    set_deviceid(from.deviceid());
  }
  if (from.endpoint() != 0) {
    set_endpoint(from.endpoint());
  }
}

void SwBle_t::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:SwBle_t)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SwBle_t::CopyFrom(const SwBle_t& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SwBle_t)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SwBle_t::IsInitialized() const {
  return true;
}

void SwBle_t::Swap(SwBle_t* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SwBle_t::InternalSwap(SwBle_t* other) {
  using std::swap;
  swap(status_, other->status_);
  swap(deviceid_, other->deviceid_);
  swap(endpoint_, other->endpoint_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata SwBle_t::GetMetadata() const {
  protobuf_ble_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_ble_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::Ble_t* Arena::CreateMaybeMessage< ::Ble_t >(Arena* arena) {
  return Arena::CreateInternal< ::Ble_t >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::SwBle_t* Arena::CreateMaybeMessage< ::SwBle_t >(Arena* arena) {
  return Arena::CreateInternal< ::SwBle_t >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
