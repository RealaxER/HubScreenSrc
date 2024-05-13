# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: typedef.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='typedef.proto',
  package='',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n\rtypedef.proto\"2\n\x05Led_t\x12\x0c\n\x04name\x18\x10 \x01(\t\x12\x0b\n\x03mac\x18\x11 \x01(\x04\x12\x0e\n\x06status\x18\x12 \x01(\x08\"=\n\x04Sw_t\x12\x0c\n\x04name\x18\x10 \x01(\t\x12\n\n\x02\x65p\x18\x11 \x01(\r\x12\x0b\n\x03mac\x18\x12 \x01(\x04\x12\x0e\n\x06status\x18\x13 \x01(\x08\"7\n\x05Ota_t\x12\x11\n\tcheck_ota\x18\x10 \x01(\x08\x12\x0e\n\x06status\x18\x11 \x01(\x08\x12\x0b\n\x03\x61\x63k\x18\x12 \x01(\x08\"&\n\x0bKeepAlive_t\x12\x17\n\x06sender\x18\x01 \x01(\x0e\x32\x07.User_t\"\xbb\x01\n\x06\x42uffer\x12\x0f\n\x07mac_hub\x18\x01 \x01(\t\x12\x17\n\x06sender\x18\x02 \x01(\x0e\x32\x07.User_t\x12\x19\n\x08receiver\x18\x03 \x01(\x0e\x32\x07.User_t\x12\x1a\n\tcotroller\x18\x04 \x01(\x0e\x32\x07.User_t\x12\x13\n\x03ota\x18\x10 \x01(\x0b\x32\x06.Ota_t\x12\x13\n\x03vpn\x18\x11 \x01(\x0b\x32\x06.Vpn_t\x12\x13\n\x03led\x18\x12 \x03(\x0b\x32\x06.Led_t\x12\x11\n\x02sw\x18\x13 \x03(\x0b\x32\x05.Sw_t\"$\n\x05Vpn_t\x12\x0e\n\x06status\x18\x01 \x01(\x08\x12\x0b\n\x03mac\x18\x02 \x01(\t\"9\n\x08Vendor_t\x12\x0f\n\x07mac_ven\x18\x01 \x01(\t\x12\x0c\n\x04\x64\x61ta\x18\x02 \x01(\t\x12\x0e\n\x06status\x18\x03 \x01(\x08*b\n\x06User_t\x12\x07\n\x03\x41pp\x10\x00\x12\n\n\x06Server\x10\x01\x12\x07\n\x03Hub\x10\x02\x12\n\n\x06Zigbee\x10\x03\x12\x07\n\x03\x42le\x10\x04\x12\x06\n\x02\x41i\x10\x05\x12\x08\n\x04Wifi\x10\x06\x12\n\n\x06Screen\x10\x07\x12\x07\n\x03Ota\x10\x08\x62\x06proto3')
)

_USER_T = _descriptor.EnumDescriptor(
  name='User_t',
  full_name='User_t',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='App', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='Server', index=1, number=1,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='Hub', index=2, number=2,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='Zigbee', index=3, number=3,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='Ble', index=4, number=4,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='Ai', index=5, number=5,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='Wifi', index=6, number=6,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='Screen', index=7, number=7,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='Ota', index=8, number=8,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=516,
  serialized_end=614,
)
_sym_db.RegisterEnumDescriptor(_USER_T)

User_t = enum_type_wrapper.EnumTypeWrapper(_USER_T)
App = 0
Server = 1
Hub = 2
Zigbee = 3
Ble = 4
Ai = 5
Wifi = 6
Screen = 7
Ota = 8



_LED_T = _descriptor.Descriptor(
  name='Led_t',
  full_name='Led_t',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='name', full_name='Led_t.name', index=0,
      number=16, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='mac', full_name='Led_t.mac', index=1,
      number=17, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='status', full_name='Led_t.status', index=2,
      number=18, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=17,
  serialized_end=67,
)


_SW_T = _descriptor.Descriptor(
  name='Sw_t',
  full_name='Sw_t',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='name', full_name='Sw_t.name', index=0,
      number=16, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='ep', full_name='Sw_t.ep', index=1,
      number=17, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='mac', full_name='Sw_t.mac', index=2,
      number=18, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='status', full_name='Sw_t.status', index=3,
      number=19, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=69,
  serialized_end=130,
)


_OTA_T = _descriptor.Descriptor(
  name='Ota_t',
  full_name='Ota_t',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='check_ota', full_name='Ota_t.check_ota', index=0,
      number=16, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='status', full_name='Ota_t.status', index=1,
      number=17, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='ack', full_name='Ota_t.ack', index=2,
      number=18, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=132,
  serialized_end=187,
)


_KEEPALIVE_T = _descriptor.Descriptor(
  name='KeepAlive_t',
  full_name='KeepAlive_t',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='sender', full_name='KeepAlive_t.sender', index=0,
      number=1, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=189,
  serialized_end=227,
)


_BUFFER = _descriptor.Descriptor(
  name='Buffer',
  full_name='Buffer',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='mac_hub', full_name='Buffer.mac_hub', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='sender', full_name='Buffer.sender', index=1,
      number=2, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='receiver', full_name='Buffer.receiver', index=2,
      number=3, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='cotroller', full_name='Buffer.cotroller', index=3,
      number=4, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='ota', full_name='Buffer.ota', index=4,
      number=16, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='vpn', full_name='Buffer.vpn', index=5,
      number=17, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='led', full_name='Buffer.led', index=6,
      number=18, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='sw', full_name='Buffer.sw', index=7,
      number=19, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=230,
  serialized_end=417,
)


_VPN_T = _descriptor.Descriptor(
  name='Vpn_t',
  full_name='Vpn_t',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='status', full_name='Vpn_t.status', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='mac', full_name='Vpn_t.mac', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=419,
  serialized_end=455,
)


_VENDOR_T = _descriptor.Descriptor(
  name='Vendor_t',
  full_name='Vendor_t',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='mac_ven', full_name='Vendor_t.mac_ven', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='data', full_name='Vendor_t.data', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='status', full_name='Vendor_t.status', index=2,
      number=3, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=457,
  serialized_end=514,
)

_KEEPALIVE_T.fields_by_name['sender'].enum_type = _USER_T
_BUFFER.fields_by_name['sender'].enum_type = _USER_T
_BUFFER.fields_by_name['receiver'].enum_type = _USER_T
_BUFFER.fields_by_name['cotroller'].enum_type = _USER_T
_BUFFER.fields_by_name['ota'].message_type = _OTA_T
_BUFFER.fields_by_name['vpn'].message_type = _VPN_T
_BUFFER.fields_by_name['led'].message_type = _LED_T
_BUFFER.fields_by_name['sw'].message_type = _SW_T
DESCRIPTOR.message_types_by_name['Led_t'] = _LED_T
DESCRIPTOR.message_types_by_name['Sw_t'] = _SW_T
DESCRIPTOR.message_types_by_name['Ota_t'] = _OTA_T
DESCRIPTOR.message_types_by_name['KeepAlive_t'] = _KEEPALIVE_T
DESCRIPTOR.message_types_by_name['Buffer'] = _BUFFER
DESCRIPTOR.message_types_by_name['Vpn_t'] = _VPN_T
DESCRIPTOR.message_types_by_name['Vendor_t'] = _VENDOR_T
DESCRIPTOR.enum_types_by_name['User_t'] = _USER_T
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Led_t = _reflection.GeneratedProtocolMessageType('Led_t', (_message.Message,), dict(
  DESCRIPTOR = _LED_T,
  __module__ = 'typedef_pb2'
  # @@protoc_insertion_point(class_scope:Led_t)
  ))
_sym_db.RegisterMessage(Led_t)

Sw_t = _reflection.GeneratedProtocolMessageType('Sw_t', (_message.Message,), dict(
  DESCRIPTOR = _SW_T,
  __module__ = 'typedef_pb2'
  # @@protoc_insertion_point(class_scope:Sw_t)
  ))
_sym_db.RegisterMessage(Sw_t)

Ota_t = _reflection.GeneratedProtocolMessageType('Ota_t', (_message.Message,), dict(
  DESCRIPTOR = _OTA_T,
  __module__ = 'typedef_pb2'
  # @@protoc_insertion_point(class_scope:Ota_t)
  ))
_sym_db.RegisterMessage(Ota_t)

KeepAlive_t = _reflection.GeneratedProtocolMessageType('KeepAlive_t', (_message.Message,), dict(
  DESCRIPTOR = _KEEPALIVE_T,
  __module__ = 'typedef_pb2'
  # @@protoc_insertion_point(class_scope:KeepAlive_t)
  ))
_sym_db.RegisterMessage(KeepAlive_t)

Buffer = _reflection.GeneratedProtocolMessageType('Buffer', (_message.Message,), dict(
  DESCRIPTOR = _BUFFER,
  __module__ = 'typedef_pb2'
  # @@protoc_insertion_point(class_scope:Buffer)
  ))
_sym_db.RegisterMessage(Buffer)

Vpn_t = _reflection.GeneratedProtocolMessageType('Vpn_t', (_message.Message,), dict(
  DESCRIPTOR = _VPN_T,
  __module__ = 'typedef_pb2'
  # @@protoc_insertion_point(class_scope:Vpn_t)
  ))
_sym_db.RegisterMessage(Vpn_t)

Vendor_t = _reflection.GeneratedProtocolMessageType('Vendor_t', (_message.Message,), dict(
  DESCRIPTOR = _VENDOR_T,
  __module__ = 'typedef_pb2'
  # @@protoc_insertion_point(class_scope:Vendor_t)
  ))
_sym_db.RegisterMessage(Vendor_t)


# @@protoc_insertion_point(module_scope)