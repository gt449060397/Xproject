// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: basicParameters.proto

#include "basicParameters.pb.h"

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
namespace Xproject {
class BasicParametersDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<BasicParameters> _instance;
} _BasicParameters_default_instance_;
}  // namespace Xproject
static void InitDefaultsscc_info_BasicParameters_basicParameters_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::Xproject::_BasicParameters_default_instance_;
    new (ptr) ::Xproject::BasicParameters();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Xproject::BasicParameters::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_BasicParameters_basicParameters_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_BasicParameters_basicParameters_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_basicParameters_2eproto[1];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_basicParameters_2eproto[6];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_basicParameters_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_basicParameters_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Xproject::BasicParameters, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Xproject::BasicParameters, w0_),
  PROTOBUF_FIELD_OFFSET(::Xproject::BasicParameters, m_edesignyears_),
  PROTOBUF_FIELD_OFFSET(::Xproject::BasicParameters, m_esitetype_),
  PROTOBUF_FIELD_OFFSET(::Xproject::BasicParameters, m_ecalarea_),
  PROTOBUF_FIELD_OFFSET(::Xproject::BasicParameters, m_ewindcalmethod_),
  PROTOBUF_FIELD_OFFSET(::Xproject::BasicParameters, m_eseismicfort_),
  PROTOBUF_FIELD_OFFSET(::Xproject::BasicParameters, m_eseismicsitetype_),
  PROTOBUF_FIELD_OFFSET(::Xproject::BasicParameters, m_u_sl_),
  PROTOBUF_FIELD_OFFSET(::Xproject::BasicParameters, m_windloadnominalvalue_),
  PROTOBUF_FIELD_OFFSET(::Xproject::BasicParameters, m_alpha_max_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Xproject::BasicParameters)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Xproject::_BasicParameters_default_instance_),
};

const char descriptor_table_protodef_basicParameters_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025basicParameters.proto\022\010Xproject\"\272\006\n\017Ba"
  "sicParameters\022\n\n\002w0\030\001 \001(\001\022=\n\016m_eDesignYe"
  "ars\030\002 \001(\0162%.Xproject.BasicParameters.Des"
  "ignYears\0227\n\013m_eSiteType\030\003 \001(\0162\".Xproject"
  ".BasicParameters.SiteType\022;\n\nm_eCalArea\030"
  "\004 \001(\0162\'.Xproject.BasicParameters.Calcula"
  "teArea\022E\n\020m_eWindCalMethod\030\005 \001(\0162+.Xproj"
  "ect.BasicParameters.WindLoadCalMethod\022F\n"
  "\016m_eSeismicFort\030\006 \001(\0162..Xproject.BasicPa"
  "rameters.SeismicFortification\022E\n\022m_eSeis"
  "micSiteType\030\007 \001(\0162).Xproject.BasicParame"
  "ters.SeismicSiteType\022\016\n\006m_u_sl\030\010 \001(\001\022\036\n\026"
  "m_WindLoadNominalValue\030\t \001(\001\022\023\n\013m_alpha_"
  "max\030\n \001(\001\"%\n\013DesignYears\022\t\n\005FIFTY\020\000\022\013\n\007H"
  "UNDRED\020\001\"&\n\010SiteType\022\005\n\001A\020\000\022\005\n\001B\020\001\022\005\n\001C\020"
  "\002\022\005\n\001D\020\003\"0\n\rCalculateArea\022\n\n\006Corner\020\000\022\010\n"
  "\004Wall\020\001\022\t\n\005Other\020\002\"M\n\024SeismicFortificati"
  "on\022\014\n\010STANDARD\020\000\022\014\n\010EMPHASIS\020\001\022\013\n\007SPECIA"
  "L\020\002\022\014\n\010MODERATE\020\003\":\n\017SeismicSiteType\022\006\n\002"
  "I0\020\000\022\006\n\002I1\020\001\022\006\n\002II\020\002\022\007\n\003III\020\003\022\006\n\002IV\020\004\"\?\n"
  "\021WindLoadCalMethod\022\014\n\010LOADCODE\020\000\022\r\n\tCUST"
  "OMIZE\020\001\022\r\n\tACTUALCAL\020\002b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_basicParameters_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_basicParameters_2eproto_sccs[1] = {
  &scc_info_BasicParameters_basicParameters_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_basicParameters_2eproto_once;
static bool descriptor_table_basicParameters_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_basicParameters_2eproto = {
  &descriptor_table_basicParameters_2eproto_initialized, descriptor_table_protodef_basicParameters_2eproto, "basicParameters.proto", 870,
  &descriptor_table_basicParameters_2eproto_once, descriptor_table_basicParameters_2eproto_sccs, descriptor_table_basicParameters_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_basicParameters_2eproto::offsets,
  file_level_metadata_basicParameters_2eproto, 1, file_level_enum_descriptors_basicParameters_2eproto, file_level_service_descriptors_basicParameters_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_basicParameters_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_basicParameters_2eproto), true);
namespace Xproject {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BasicParameters_DesignYears_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_basicParameters_2eproto);
  return file_level_enum_descriptors_basicParameters_2eproto[0];
}
bool BasicParameters_DesignYears_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr BasicParameters_DesignYears BasicParameters::FIFTY;
constexpr BasicParameters_DesignYears BasicParameters::HUNDRED;
constexpr BasicParameters_DesignYears BasicParameters::DesignYears_MIN;
constexpr BasicParameters_DesignYears BasicParameters::DesignYears_MAX;
constexpr int BasicParameters::DesignYears_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BasicParameters_SiteType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_basicParameters_2eproto);
  return file_level_enum_descriptors_basicParameters_2eproto[1];
}
bool BasicParameters_SiteType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr BasicParameters_SiteType BasicParameters::A;
constexpr BasicParameters_SiteType BasicParameters::B;
constexpr BasicParameters_SiteType BasicParameters::C;
constexpr BasicParameters_SiteType BasicParameters::D;
constexpr BasicParameters_SiteType BasicParameters::SiteType_MIN;
constexpr BasicParameters_SiteType BasicParameters::SiteType_MAX;
constexpr int BasicParameters::SiteType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BasicParameters_CalculateArea_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_basicParameters_2eproto);
  return file_level_enum_descriptors_basicParameters_2eproto[2];
}
bool BasicParameters_CalculateArea_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr BasicParameters_CalculateArea BasicParameters::Corner;
constexpr BasicParameters_CalculateArea BasicParameters::Wall;
constexpr BasicParameters_CalculateArea BasicParameters::Other;
constexpr BasicParameters_CalculateArea BasicParameters::CalculateArea_MIN;
constexpr BasicParameters_CalculateArea BasicParameters::CalculateArea_MAX;
constexpr int BasicParameters::CalculateArea_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BasicParameters_SeismicFortification_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_basicParameters_2eproto);
  return file_level_enum_descriptors_basicParameters_2eproto[3];
}
bool BasicParameters_SeismicFortification_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr BasicParameters_SeismicFortification BasicParameters::STANDARD;
constexpr BasicParameters_SeismicFortification BasicParameters::EMPHASIS;
constexpr BasicParameters_SeismicFortification BasicParameters::SPECIAL;
constexpr BasicParameters_SeismicFortification BasicParameters::MODERATE;
constexpr BasicParameters_SeismicFortification BasicParameters::SeismicFortification_MIN;
constexpr BasicParameters_SeismicFortification BasicParameters::SeismicFortification_MAX;
constexpr int BasicParameters::SeismicFortification_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BasicParameters_SeismicSiteType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_basicParameters_2eproto);
  return file_level_enum_descriptors_basicParameters_2eproto[4];
}
bool BasicParameters_SeismicSiteType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr BasicParameters_SeismicSiteType BasicParameters::I0;
constexpr BasicParameters_SeismicSiteType BasicParameters::I1;
constexpr BasicParameters_SeismicSiteType BasicParameters::II;
constexpr BasicParameters_SeismicSiteType BasicParameters::III;
constexpr BasicParameters_SeismicSiteType BasicParameters::IV;
constexpr BasicParameters_SeismicSiteType BasicParameters::SeismicSiteType_MIN;
constexpr BasicParameters_SeismicSiteType BasicParameters::SeismicSiteType_MAX;
constexpr int BasicParameters::SeismicSiteType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BasicParameters_WindLoadCalMethod_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_basicParameters_2eproto);
  return file_level_enum_descriptors_basicParameters_2eproto[5];
}
bool BasicParameters_WindLoadCalMethod_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr BasicParameters_WindLoadCalMethod BasicParameters::LOADCODE;
constexpr BasicParameters_WindLoadCalMethod BasicParameters::CUSTOMIZE;
constexpr BasicParameters_WindLoadCalMethod BasicParameters::ACTUALCAL;
constexpr BasicParameters_WindLoadCalMethod BasicParameters::WindLoadCalMethod_MIN;
constexpr BasicParameters_WindLoadCalMethod BasicParameters::WindLoadCalMethod_MAX;
constexpr int BasicParameters::WindLoadCalMethod_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

void BasicParameters::InitAsDefaultInstance() {
}
class BasicParameters::_Internal {
 public:
};

BasicParameters::BasicParameters()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Xproject.BasicParameters)
}
BasicParameters::BasicParameters(const BasicParameters& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&w0_, &from.w0_,
    static_cast<size_t>(reinterpret_cast<char*>(&m_alpha_max_) -
    reinterpret_cast<char*>(&w0_)) + sizeof(m_alpha_max_));
  // @@protoc_insertion_point(copy_constructor:Xproject.BasicParameters)
}

void BasicParameters::SharedCtor() {
  ::memset(&w0_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&m_alpha_max_) -
      reinterpret_cast<char*>(&w0_)) + sizeof(m_alpha_max_));
}

BasicParameters::~BasicParameters() {
  // @@protoc_insertion_point(destructor:Xproject.BasicParameters)
  SharedDtor();
}

void BasicParameters::SharedDtor() {
}

void BasicParameters::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const BasicParameters& BasicParameters::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_BasicParameters_basicParameters_2eproto.base);
  return *internal_default_instance();
}


void BasicParameters::Clear() {
// @@protoc_insertion_point(message_clear_start:Xproject.BasicParameters)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&w0_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&m_alpha_max_) -
      reinterpret_cast<char*>(&w0_)) + sizeof(m_alpha_max_));
  _internal_metadata_.Clear();
}

const char* BasicParameters::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // double w0 = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 9)) {
          w0_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // .Xproject.BasicParameters.DesignYears m_eDesignYears = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          _internal_set_m_edesignyears(static_cast<::Xproject::BasicParameters_DesignYears>(val));
        } else goto handle_unusual;
        continue;
      // .Xproject.BasicParameters.SiteType m_eSiteType = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          _internal_set_m_esitetype(static_cast<::Xproject::BasicParameters_SiteType>(val));
        } else goto handle_unusual;
        continue;
      // .Xproject.BasicParameters.CalculateArea m_eCalArea = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          _internal_set_m_ecalarea(static_cast<::Xproject::BasicParameters_CalculateArea>(val));
        } else goto handle_unusual;
        continue;
      // .Xproject.BasicParameters.WindLoadCalMethod m_eWindCalMethod = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          _internal_set_m_ewindcalmethod(static_cast<::Xproject::BasicParameters_WindLoadCalMethod>(val));
        } else goto handle_unusual;
        continue;
      // .Xproject.BasicParameters.SeismicFortification m_eSeismicFort = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          _internal_set_m_eseismicfort(static_cast<::Xproject::BasicParameters_SeismicFortification>(val));
        } else goto handle_unusual;
        continue;
      // .Xproject.BasicParameters.SeismicSiteType m_eSeismicSiteType = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 56)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          _internal_set_m_eseismicsitetype(static_cast<::Xproject::BasicParameters_SeismicSiteType>(val));
        } else goto handle_unusual;
        continue;
      // double m_u_sl = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 65)) {
          m_u_sl_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double m_WindLoadNominalValue = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 73)) {
          m_windloadnominalvalue_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double m_alpha_max = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 81)) {
          m_alpha_max_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* BasicParameters::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Xproject.BasicParameters)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // double w0 = 1;
  if (!(this->w0() <= 0 && this->w0() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(1, this->_internal_w0(), target);
  }

  // .Xproject.BasicParameters.DesignYears m_eDesignYears = 2;
  if (this->m_edesignyears() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      2, this->_internal_m_edesignyears(), target);
  }

  // .Xproject.BasicParameters.SiteType m_eSiteType = 3;
  if (this->m_esitetype() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      3, this->_internal_m_esitetype(), target);
  }

  // .Xproject.BasicParameters.CalculateArea m_eCalArea = 4;
  if (this->m_ecalarea() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      4, this->_internal_m_ecalarea(), target);
  }

  // .Xproject.BasicParameters.WindLoadCalMethod m_eWindCalMethod = 5;
  if (this->m_ewindcalmethod() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      5, this->_internal_m_ewindcalmethod(), target);
  }

  // .Xproject.BasicParameters.SeismicFortification m_eSeismicFort = 6;
  if (this->m_eseismicfort() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      6, this->_internal_m_eseismicfort(), target);
  }

  // .Xproject.BasicParameters.SeismicSiteType m_eSeismicSiteType = 7;
  if (this->m_eseismicsitetype() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      7, this->_internal_m_eseismicsitetype(), target);
  }

  // double m_u_sl = 8;
  if (!(this->m_u_sl() <= 0 && this->m_u_sl() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(8, this->_internal_m_u_sl(), target);
  }

  // double m_WindLoadNominalValue = 9;
  if (!(this->m_windloadnominalvalue() <= 0 && this->m_windloadnominalvalue() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(9, this->_internal_m_windloadnominalvalue(), target);
  }

  // double m_alpha_max = 10;
  if (!(this->m_alpha_max() <= 0 && this->m_alpha_max() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(10, this->_internal_m_alpha_max(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Xproject.BasicParameters)
  return target;
}

size_t BasicParameters::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Xproject.BasicParameters)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // double w0 = 1;
  if (!(this->w0() <= 0 && this->w0() >= 0)) {
    total_size += 1 + 8;
  }

  // .Xproject.BasicParameters.DesignYears m_eDesignYears = 2;
  if (this->m_edesignyears() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_m_edesignyears());
  }

  // .Xproject.BasicParameters.SiteType m_eSiteType = 3;
  if (this->m_esitetype() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_m_esitetype());
  }

  // .Xproject.BasicParameters.CalculateArea m_eCalArea = 4;
  if (this->m_ecalarea() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_m_ecalarea());
  }

  // .Xproject.BasicParameters.WindLoadCalMethod m_eWindCalMethod = 5;
  if (this->m_ewindcalmethod() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_m_ewindcalmethod());
  }

  // .Xproject.BasicParameters.SeismicFortification m_eSeismicFort = 6;
  if (this->m_eseismicfort() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_m_eseismicfort());
  }

  // .Xproject.BasicParameters.SeismicSiteType m_eSeismicSiteType = 7;
  if (this->m_eseismicsitetype() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_m_eseismicsitetype());
  }

  // double m_u_sl = 8;
  if (!(this->m_u_sl() <= 0 && this->m_u_sl() >= 0)) {
    total_size += 1 + 8;
  }

  // double m_WindLoadNominalValue = 9;
  if (!(this->m_windloadnominalvalue() <= 0 && this->m_windloadnominalvalue() >= 0)) {
    total_size += 1 + 8;
  }

  // double m_alpha_max = 10;
  if (!(this->m_alpha_max() <= 0 && this->m_alpha_max() >= 0)) {
    total_size += 1 + 8;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void BasicParameters::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Xproject.BasicParameters)
  GOOGLE_DCHECK_NE(&from, this);
  const BasicParameters* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<BasicParameters>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Xproject.BasicParameters)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Xproject.BasicParameters)
    MergeFrom(*source);
  }
}

void BasicParameters::MergeFrom(const BasicParameters& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Xproject.BasicParameters)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!(from.w0() <= 0 && from.w0() >= 0)) {
    _internal_set_w0(from._internal_w0());
  }
  if (from.m_edesignyears() != 0) {
    _internal_set_m_edesignyears(from._internal_m_edesignyears());
  }
  if (from.m_esitetype() != 0) {
    _internal_set_m_esitetype(from._internal_m_esitetype());
  }
  if (from.m_ecalarea() != 0) {
    _internal_set_m_ecalarea(from._internal_m_ecalarea());
  }
  if (from.m_ewindcalmethod() != 0) {
    _internal_set_m_ewindcalmethod(from._internal_m_ewindcalmethod());
  }
  if (from.m_eseismicfort() != 0) {
    _internal_set_m_eseismicfort(from._internal_m_eseismicfort());
  }
  if (from.m_eseismicsitetype() != 0) {
    _internal_set_m_eseismicsitetype(from._internal_m_eseismicsitetype());
  }
  if (!(from.m_u_sl() <= 0 && from.m_u_sl() >= 0)) {
    _internal_set_m_u_sl(from._internal_m_u_sl());
  }
  if (!(from.m_windloadnominalvalue() <= 0 && from.m_windloadnominalvalue() >= 0)) {
    _internal_set_m_windloadnominalvalue(from._internal_m_windloadnominalvalue());
  }
  if (!(from.m_alpha_max() <= 0 && from.m_alpha_max() >= 0)) {
    _internal_set_m_alpha_max(from._internal_m_alpha_max());
  }
}

void BasicParameters::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Xproject.BasicParameters)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BasicParameters::CopyFrom(const BasicParameters& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Xproject.BasicParameters)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BasicParameters::IsInitialized() const {
  return true;
}

void BasicParameters::InternalSwap(BasicParameters* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(w0_, other->w0_);
  swap(m_edesignyears_, other->m_edesignyears_);
  swap(m_esitetype_, other->m_esitetype_);
  swap(m_ecalarea_, other->m_ecalarea_);
  swap(m_ewindcalmethod_, other->m_ewindcalmethod_);
  swap(m_eseismicfort_, other->m_eseismicfort_);
  swap(m_eseismicsitetype_, other->m_eseismicsitetype_);
  swap(m_u_sl_, other->m_u_sl_);
  swap(m_windloadnominalvalue_, other->m_windloadnominalvalue_);
  swap(m_alpha_max_, other->m_alpha_max_);
}

::PROTOBUF_NAMESPACE_ID::Metadata BasicParameters::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Xproject
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Xproject::BasicParameters* Arena::CreateMaybeMessage< ::Xproject::BasicParameters >(Arena* arena) {
  return Arena::CreateInternal< ::Xproject::BasicParameters >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
