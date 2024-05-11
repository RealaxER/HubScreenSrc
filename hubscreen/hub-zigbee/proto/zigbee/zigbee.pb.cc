// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: zigbee.proto

#include "zigbee.pb.h"

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

namespace protobuf_zigbee_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_zigbee_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_SwZb_t;
}  // namespace protobuf_zigbee_2eproto
class Zigbee_tDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Zigbee_t>
      _instance;
} _Zigbee_t_default_instance_;
class SwZb_tDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<SwZb_t>
      _instance;
} _SwZb_t_default_instance_;
namespace protobuf_zigbee_2eproto {
static void InitDefaultsZigbee_t() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Zigbee_t_default_instance_;
    new (ptr) ::Zigbee_t();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Zigbee_t::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_Zigbee_t =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsZigbee_t}, {
      &protobuf_zigbee_2eproto::scc_info_SwZb_t.base,}};

static void InitDefaultsSwZb_t() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_SwZb_t_default_instance_;
    new (ptr) ::SwZb_t();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::SwZb_t::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_SwZb_t =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsSwZb_t}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Zigbee_t.base);
  ::google::protobuf::internal::InitSCC(&scc_info_SwZb_t.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Zigbee_t, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Zigbee_t, led_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Zigbee_t, sync_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SwZb_t, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SwZb_t, deviceid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SwZb_t, endpoint_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SwZb_t, status_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Zigbee_t)},
  { 7, -1, sizeof(::SwZb_t)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_Zigbee_t_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::_SwZb_t_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "zigbee.proto", schemas, file_default_instances, TableStruct::offsets,
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
      "\n\014zigbee.proto\".\n\010Zigbee_t\022\024\n\003led\030\001 \001(\0132"
      "\007.SwZb_t\022\014\n\004sync\030\002 \001(\010\"<\n\006SwZb_t\022\020\n\010devi"
      "ceID\030\001 \001(\r\022\020\n\010endpoint\030\002 \001(\004\022\016\n\006status\030\003"
      " \001(\010b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 132);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "zigbee.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_zigbee_2eproto

// ===================================================================

void Zigbee_t::InitAsDefaultInstance() {
  ::_Zigbee_t_default_instance_._instance.get_mutable()->led_ = const_cast< ::SwZb_t*>(
      ::SwZb_t::internal_default_instance());
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Zigbee_t::kLedFieldNumber;
const int Zigbee_t::kSyncFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Zigbee_t::Zigbee_t()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_zigbee_2eproto::scc_info_Zigbee_t.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:Zigbee_t)
}
Zigbee_t::Zigbee_t(const Zigbee_t& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_led()) {
    led_ = new ::SwZb_t(*from.led_);
  } else {
    led_ = NULL;
  }
  sync_ = from.sync_;
  // @@protoc_insertion_point(copy_constructor:Zigbee_t)
}

void Zigbee_t::SharedCtor() {
  ::memset(&led_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&sync_) -
      reinterpret_cast<char*>(&led_)) + sizeof(sync_));
}

Zigbee_t::~Zigbee_t() {
  // @@protoc_insertion_point(destructor:Zigbee_t)
  SharedDtor();
}

void Zigbee_t::SharedDtor() {
  if (this != internal_default_instance()) delete led_;
}

void Zigbee_t::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Zigbee_t::descriptor() {
  ::protobuf_zigbee_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_zigbee_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Zigbee_t& Zigbee_t::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_zigbee_2eproto::scc_info_Zigbee_t.base);
  return *internal_default_instance();
}


void Zigbee_t::Clear() {
// @@protoc_insertion_point(message_clear_start:Zigbee_t)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaNoVirtual() == NULL && led_ != NULL) {
    delete led_;
  }
  led_ = NULL;
  sync_ = false;
  _internal_metadata_.Clear();
}

bool Zigbee_t::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Zigbee_t)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .SwZb_t led = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_led()));
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
  // @@protoc_insertion_point(parse_success:Zigbee_t)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Zigbee_t)
  return false;
#undef DO_
}

void Zigbee_t::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Zigbee_t)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .SwZb_t led = 1;
  if (this->has_led()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->_internal_led(), output);
  }

  // bool sync = 2;
  if (this->sync() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->sync(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:Zigbee_t)
}

::google::protobuf::uint8* Zigbee_t::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Zigbee_t)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .SwZb_t led = 1;
  if (this->has_led()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->_internal_led(), deterministic, target);
  }

  // bool sync = 2;
  if (this->sync() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->sync(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Zigbee_t)
  return target;
}

size_t Zigbee_t::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Zigbee_t)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // .SwZb_t led = 1;
  if (this->has_led()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *led_);
  }

  // bool sync = 2;
  if (this->sync() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Zigbee_t::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Zigbee_t)
  GOOGLE_DCHECK_NE(&from, this);
  const Zigbee_t* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Zigbee_t>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Zigbee_t)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Zigbee_t)
    MergeFrom(*source);
  }
}

void Zigbee_t::MergeFrom(const Zigbee_t& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Zigbee_t)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_led()) {
    mutable_led()->::SwZb_t::MergeFrom(from.led());
  }
  if (from.sync() != 0) {
    set_sync(from.sync());
  }
}

void Zigbee_t::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Zigbee_t)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Zigbee_t::CopyFrom(const Zigbee_t& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Zigbee_t)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Zigbee_t::IsInitialized() const {
  return true;
}

void Zigbee_t::Swap(Zigbee_t* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Zigbee_t::InternalSwap(Zigbee_t* other) {
  using std::swap;
  swap(led_, other->led_);
  swap(sync_, other->sync_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Zigbee_t::GetMetadata() const {
  protobuf_zigbee_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_zigbee_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void SwZb_t::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SwZb_t::kDeviceIDFieldNumber;
const int SwZb_t::kEndpointFieldNumber;
const int SwZb_t::kStatusFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SwZb_t::SwZb_t()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_zigbee_2eproto::scc_info_SwZb_t.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:SwZb_t)
}
SwZb_t::SwZb_t(const SwZb_t& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&endpoint_, &from.endpoint_,
    static_cast<size_t>(reinterpret_cast<char*>(&status_) -
    reinterpret_cast<char*>(&endpoint_)) + sizeof(status_));
  // @@protoc_insertion_point(copy_constructor:SwZb_t)
}

void SwZb_t::SharedCtor() {
  ::memset(&endpoint_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&status_) -
      reinterpret_cast<char*>(&endpoint_)) + sizeof(status_));
}

SwZb_t::~SwZb_t() {
  // @@protoc_insertion_point(destructor:SwZb_t)
  SharedDtor();
}

void SwZb_t::SharedDtor() {
}

void SwZb_t::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* SwZb_t::descriptor() {
  ::protobuf_zigbee_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_zigbee_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const SwZb_t& SwZb_t::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_zigbee_2eproto::scc_info_SwZb_t.base);
  return *internal_default_instance();
}


void SwZb_t::Clear() {
// @@protoc_insertion_point(message_clear_start:SwZb_t)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&endpoint_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&status_) -
      reinterpret_cast<char*>(&endpoint_)) + sizeof(status_));
  _internal_metadata_.Clear();
}

bool SwZb_t::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SwZb_t)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // uint32 deviceID = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &deviceid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint64 endpoint = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &endpoint_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool status = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {

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
  // @@protoc_insertion_point(parse_success:SwZb_t)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SwZb_t)
  return false;
#undef DO_
}

void SwZb_t::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SwZb_t)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 deviceID = 1;
  if (this->deviceid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->deviceid(), output);
  }

  // uint64 endpoint = 2;
  if (this->endpoint() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->endpoint(), output);
  }

  // bool status = 3;
  if (this->status() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->status(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:SwZb_t)
}

::google::protobuf::uint8* SwZb_t::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:SwZb_t)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 deviceID = 1;
  if (this->deviceid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->deviceid(), target);
  }

  // uint64 endpoint = 2;
  if (this->endpoint() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->endpoint(), target);
  }

  // bool status = 3;
  if (this->status() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->status(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SwZb_t)
  return target;
}

size_t SwZb_t::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:SwZb_t)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // uint64 endpoint = 2;
  if (this->endpoint() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->endpoint());
  }

  // uint32 deviceID = 1;
  if (this->deviceid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->deviceid());
  }

  // bool status = 3;
  if (this->status() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SwZb_t::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:SwZb_t)
  GOOGLE_DCHECK_NE(&from, this);
  const SwZb_t* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const SwZb_t>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:SwZb_t)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:SwZb_t)
    MergeFrom(*source);
  }
}

void SwZb_t::MergeFrom(const SwZb_t& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:SwZb_t)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.endpoint() != 0) {
    set_endpoint(from.endpoint());
  }
  if (from.deviceid() != 0) {
    set_deviceid(from.deviceid());
  }
  if (from.status() != 0) {
    set_status(from.status());
  }
}

void SwZb_t::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:SwZb_t)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SwZb_t::CopyFrom(const SwZb_t& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SwZb_t)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SwZb_t::IsInitialized() const {
  return true;
}

void SwZb_t::Swap(SwZb_t* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SwZb_t::InternalSwap(SwZb_t* other) {
  using std::swap;
  swap(endpoint_, other->endpoint_);
  swap(deviceid_, other->deviceid_);
  swap(status_, other->status_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata SwZb_t::GetMetadata() const {
  protobuf_zigbee_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_zigbee_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::Zigbee_t* Arena::CreateMaybeMessage< ::Zigbee_t >(Arena* arena) {
  return Arena::CreateInternal< ::Zigbee_t >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::SwZb_t* Arena::CreateMaybeMessage< ::SwZb_t >(Arena* arena) {
  return Arena::CreateInternal< ::SwZb_t >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
