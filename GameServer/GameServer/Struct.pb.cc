// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Struct.proto

#include "Struct.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace Protocol {
constexpr BuffData::BuffData(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : victims_()
  , _victims_cached_byte_size_(0)
  , buffid_(uint64_t{0u})
  , remaintime_(0){}
struct BuffDataDefaultTypeInternal {
  constexpr BuffDataDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~BuffDataDefaultTypeInternal() {}
  union {
    BuffData _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT BuffDataDefaultTypeInternal _BuffData_default_instance_;
}  // namespace Protocol
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Struct_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Struct_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Struct_2eproto = nullptr;

const uint32_t TableStruct_Struct_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, buffid_),
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, remaintime_),
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, victims_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Protocol::BuffData)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Protocol::_BuffData_default_instance_),
};

const char descriptor_table_protodef_Struct_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014Struct.proto\022\010Protocol\032\nEnum.proto\"\?\n\010"
  "BuffData\022\016\n\006buffId\030\001 \001(\004\022\022\n\nremainTime\030\002"
  " \001(\002\022\017\n\007victims\030\003 \003(\004b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_Struct_2eproto_deps[1] = {
  &::descriptor_table_Enum_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Struct_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Struct_2eproto = {
  false, false, 109, descriptor_table_protodef_Struct_2eproto, "Struct.proto", 
  &descriptor_table_Struct_2eproto_once, descriptor_table_Struct_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_Struct_2eproto::offsets,
  file_level_metadata_Struct_2eproto, file_level_enum_descriptors_Struct_2eproto, file_level_service_descriptors_Struct_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_Struct_2eproto_getter() {
  return &descriptor_table_Struct_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Struct_2eproto(&descriptor_table_Struct_2eproto);
namespace Protocol {

// ===================================================================

class BuffData::_Internal {
 public:
};

BuffData::BuffData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  victims_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Protocol.BuffData)
}
BuffData::BuffData(const BuffData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      victims_(from.victims_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&buffid_, &from.buffid_,
    static_cast<size_t>(reinterpret_cast<char*>(&remaintime_) -
    reinterpret_cast<char*>(&buffid_)) + sizeof(remaintime_));
  // @@protoc_insertion_point(copy_constructor:Protocol.BuffData)
}

inline void BuffData::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&buffid_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&remaintime_) -
    reinterpret_cast<char*>(&buffid_)) + sizeof(remaintime_));
}

BuffData::~BuffData() {
  // @@protoc_insertion_point(destructor:Protocol.BuffData)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void BuffData::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void BuffData::ArenaDtor(void* object) {
  BuffData* _this = reinterpret_cast< BuffData* >(object);
  (void)_this;
}
void BuffData::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void BuffData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void BuffData::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.BuffData)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  victims_.Clear();
  ::memset(&buffid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&remaintime_) -
      reinterpret_cast<char*>(&buffid_)) + sizeof(remaintime_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BuffData::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint64 buffId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          buffid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // float remainTime = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 21)) {
          remaintime_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // repeated uint64 victims = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedUInt64Parser(_internal_mutable_victims(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 24) {
          _internal_add_victims(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* BuffData::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.BuffData)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 buffId = 1;
  if (this->_internal_buffid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(1, this->_internal_buffid(), target);
  }

  // float remainTime = 2;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_remaintime = this->_internal_remaintime();
  uint32_t raw_remaintime;
  memcpy(&raw_remaintime, &tmp_remaintime, sizeof(tmp_remaintime));
  if (raw_remaintime != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_remaintime(), target);
  }

  // repeated uint64 victims = 3;
  {
    int byte_size = _victims_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteUInt64Packed(
          3, _internal_victims(), byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.BuffData)
  return target;
}

size_t BuffData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.BuffData)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated uint64 victims = 3;
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      UInt64Size(this->victims_);
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<int32_t>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _victims_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // uint64 buffId = 1;
  if (this->_internal_buffid() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64SizePlusOne(this->_internal_buffid());
  }

  // float remainTime = 2;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_remaintime = this->_internal_remaintime();
  uint32_t raw_remaintime;
  memcpy(&raw_remaintime, &tmp_remaintime, sizeof(tmp_remaintime));
  if (raw_remaintime != 0) {
    total_size += 1 + 4;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData BuffData::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    BuffData::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*BuffData::GetClassData() const { return &_class_data_; }

void BuffData::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<BuffData *>(to)->MergeFrom(
      static_cast<const BuffData &>(from));
}


void BuffData::MergeFrom(const BuffData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.BuffData)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  victims_.MergeFrom(from.victims_);
  if (from._internal_buffid() != 0) {
    _internal_set_buffid(from._internal_buffid());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_remaintime = from._internal_remaintime();
  uint32_t raw_remaintime;
  memcpy(&raw_remaintime, &tmp_remaintime, sizeof(tmp_remaintime));
  if (raw_remaintime != 0) {
    _internal_set_remaintime(from._internal_remaintime());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void BuffData::CopyFrom(const BuffData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.BuffData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BuffData::IsInitialized() const {
  return true;
}

void BuffData::InternalSwap(BuffData* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  victims_.InternalSwap(&other->victims_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(BuffData, remaintime_)
      + sizeof(BuffData::remaintime_)
      - PROTOBUF_FIELD_OFFSET(BuffData, buffid_)>(
          reinterpret_cast<char*>(&buffid_),
          reinterpret_cast<char*>(&other->buffid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata BuffData::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Struct_2eproto_getter, &descriptor_table_Struct_2eproto_once,
      file_level_metadata_Struct_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::BuffData* Arena::CreateMaybeMessage< ::Protocol::BuffData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::BuffData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
