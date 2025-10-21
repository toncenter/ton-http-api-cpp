#pragma once
#include <tl/tlblib.hpp>
/*
 *
 *  AUTO-GENERATED FROM `/Users/ruslixag/Developer/ton-workspace/ton-http-api-cpp/ton-http-api/tlb/tokens.tlb`
 *
 */
// uses built-in type `##`
// uses built-in type `#<`
// uses built-in type `#<=`
// uses built-in type `Cell`
// uses built-in type `uint`
// uses built-in type `bits`
// uses built-in type `int8`
// uses built-in type `int32`
// uses built-in type `uint64`
// uses built-in type `bits256`

namespace tokens {

namespace gen {
using namespace ::tlb;
using td::Ref;
using td::RefInt256;
using vm::Cell;
using vm::CellSlice;

//
// headers for type `Maybe`
//

struct Maybe final : TLB_Complex {
  enum { nothing, just };
  static constexpr int cons_len_exact = 1;
  const TLB& X_;
  Maybe(const TLB& X) : X_(X) {
  }
  struct Record_nothing {
    typedef Maybe type_class;
  };
  struct Record_just {
    typedef Maybe type_class;
    Ref<CellSlice> value;  // value : X
    Record_just() = default;
    Record_just(Ref<CellSlice> _value) : value(std::move(_value)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_nothing& data) const;
  bool unpack_nothing(vm::CellSlice& cs) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_nothing& data) const;
  bool cell_unpack_nothing(Ref<vm::Cell> cell_ref) const;
  bool pack(vm::CellBuilder& cb, const Record_nothing& data) const;
  bool pack_nothing(vm::CellBuilder& cb) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_nothing& data) const;
  bool cell_pack_nothing(Ref<vm::Cell>& cell_ref) const;
  bool unpack(vm::CellSlice& cs, Record_just& data) const;
  bool unpack_just(vm::CellSlice& cs, Ref<CellSlice>& value) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_just& data) const;
  bool cell_unpack_just(Ref<vm::Cell> cell_ref, Ref<CellSlice>& value) const;
  bool pack(vm::CellBuilder& cb, const Record_just& data) const;
  bool pack_just(vm::CellBuilder& cb, Ref<CellSlice> value) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_just& data) const;
  bool cell_pack_just(Ref<vm::Cell>& cell_ref, Ref<CellSlice> value) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "(Maybe " << X_ << ")";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return (int)cs.prefetch_ulong(1);
  }
};

//
// headers for type `Either`
//

struct Either final : TLB_Complex {
  enum { left, right };
  static constexpr int cons_len_exact = 1;
  const TLB &X_, &Y_;
  Either(const TLB& X, const TLB& Y) : X_(X), Y_(Y) {
  }
  struct Record_left {
    typedef Either type_class;
    Ref<CellSlice> value;  // value : X
    Record_left() = default;
    Record_left(Ref<CellSlice> _value) : value(std::move(_value)) {
    }
  };
  struct Record_right {
    typedef Either type_class;
    Ref<CellSlice> value;  // value : Y
    Record_right() = default;
    Record_right(Ref<CellSlice> _value) : value(std::move(_value)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_left& data) const;
  bool unpack_left(vm::CellSlice& cs, Ref<CellSlice>& value) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_left& data) const;
  bool cell_unpack_left(Ref<vm::Cell> cell_ref, Ref<CellSlice>& value) const;
  bool pack(vm::CellBuilder& cb, const Record_left& data) const;
  bool pack_left(vm::CellBuilder& cb, Ref<CellSlice> value) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_left& data) const;
  bool cell_pack_left(Ref<vm::Cell>& cell_ref, Ref<CellSlice> value) const;
  bool unpack(vm::CellSlice& cs, Record_right& data) const;
  bool unpack_right(vm::CellSlice& cs, Ref<CellSlice>& value) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_right& data) const;
  bool cell_unpack_right(Ref<vm::Cell> cell_ref, Ref<CellSlice>& value) const;
  bool pack(vm::CellBuilder& cb, const Record_right& data) const;
  bool pack_right(vm::CellBuilder& cb, Ref<CellSlice> value) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_right& data) const;
  bool cell_pack_right(Ref<vm::Cell>& cell_ref, Ref<CellSlice> value) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "(Either " << X_ << " " << Y_ << ")";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return (int)cs.prefetch_ulong(1);
  }
};

//
// headers for type `VarUInteger`
//

struct VarUInteger final : TLB_Complex {
  enum { var_uint };
  static constexpr int cons_len_exact = 0;
  int m_;
  VarUInteger(int m) : m_(m) {
  }
  struct Record;
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record& data) const;
  bool unpack_var_uint(vm::CellSlice& cs, int& n, int& len, RefInt256& value) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record& data) const;
  bool cell_unpack_var_uint(Ref<vm::Cell> cell_ref, int& n, int& len, RefInt256& value) const;
  bool pack(vm::CellBuilder& cb, const Record& data) const;
  bool pack_var_uint(vm::CellBuilder& cb, int len, RefInt256 value) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record& data) const;
  bool cell_pack_var_uint(Ref<vm::Cell>& cell_ref, int len, RefInt256 value) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "(VarUInteger " << m_ << ")";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return 0;
  }
};

struct VarUInteger::Record {
  typedef VarUInteger type_class;
  int n;  // n : #
  int len;  // len : #< n
  RefInt256 value;  // value : uint (8 * len)
  Record() = default;
  Record(int _len, RefInt256 _value) : n(-1), len(_len), value(std::move(_value)) {
  }
};

//
// headers for type `MsgAddressExt`
//

struct MsgAddressExt final : TLB_Complex {
  enum { addr_none, addr_extern };
  static constexpr int cons_len_exact = 2;
  struct Record_addr_none {
    typedef MsgAddressExt type_class;
  };
  struct Record_addr_extern {
    typedef MsgAddressExt type_class;
    int len;  // len : ## 9
    Ref<td::BitString> external_address;  // external_address : bits len
    Record_addr_extern() = default;
    Record_addr_extern(int _len, Ref<td::BitString> _external_address) :
        len(_len), external_address(std::move(_external_address)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_addr_none& data) const;
  bool unpack_addr_none(vm::CellSlice& cs) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_addr_none& data) const;
  bool cell_unpack_addr_none(Ref<vm::Cell> cell_ref) const;
  bool pack(vm::CellBuilder& cb, const Record_addr_none& data) const;
  bool pack_addr_none(vm::CellBuilder& cb) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_addr_none& data) const;
  bool cell_pack_addr_none(Ref<vm::Cell>& cell_ref) const;
  bool unpack(vm::CellSlice& cs, Record_addr_extern& data) const;
  bool unpack_addr_extern(vm::CellSlice& cs, int& len, Ref<td::BitString>& external_address) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_addr_extern& data) const;
  bool cell_unpack_addr_extern(Ref<vm::Cell> cell_ref, int& len, Ref<td::BitString>& external_address) const;
  bool pack(vm::CellBuilder& cb, const Record_addr_extern& data) const;
  bool pack_addr_extern(vm::CellBuilder& cb, int len, Ref<td::BitString> external_address) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_addr_extern& data) const;
  bool cell_pack_addr_extern(Ref<vm::Cell>& cell_ref, int len, Ref<td::BitString> external_address) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "MsgAddressExt";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return cs.bselect(2, 3);
  }
};

extern const MsgAddressExt t_MsgAddressExt;

//
// headers for type `Anycast`
//

struct Anycast final : TLB_Complex {
  enum { anycast_info };
  static constexpr int cons_len_exact = 0;
  struct Record {
    typedef Anycast type_class;
    int depth;  // depth : #<= 30
    Ref<td::BitString> rewrite_pfx;  // rewrite_pfx : bits depth
    Record() = default;
    Record(int _depth, Ref<td::BitString> _rewrite_pfx) : depth(_depth), rewrite_pfx(std::move(_rewrite_pfx)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record& data) const;
  bool unpack_anycast_info(vm::CellSlice& cs, int& depth, Ref<td::BitString>& rewrite_pfx) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record& data) const;
  bool cell_unpack_anycast_info(Ref<vm::Cell> cell_ref, int& depth, Ref<td::BitString>& rewrite_pfx) const;
  bool pack(vm::CellBuilder& cb, const Record& data) const;
  bool pack_anycast_info(vm::CellBuilder& cb, int depth, Ref<td::BitString> rewrite_pfx) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record& data) const;
  bool cell_pack_anycast_info(Ref<vm::Cell>& cell_ref, int depth, Ref<td::BitString> rewrite_pfx) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "Anycast";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return 0;
  }
};

extern const Anycast t_Anycast;

//
// headers for type `MsgAddressInt`
//

struct MsgAddressInt final : TLB_Complex {
  enum { addr_std, addr_var };
  static constexpr int cons_len_exact = 2;
  static constexpr unsigned char cons_tag[2] = {2, 3};
  struct Record_addr_std;
  struct Record_addr_var;
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_addr_std& data) const;
  bool unpack_addr_std(vm::CellSlice& cs, Ref<CellSlice>& anycast, int& workchain_id, td::BitArray<256>& address) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_addr_std& data) const;
  bool cell_unpack_addr_std(
    Ref<vm::Cell> cell_ref, Ref<CellSlice>& anycast, int& workchain_id, td::BitArray<256>& address
  ) const;
  bool pack(vm::CellBuilder& cb, const Record_addr_std& data) const;
  bool pack_addr_std(vm::CellBuilder& cb, Ref<CellSlice> anycast, int workchain_id, td::BitArray<256> address) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_addr_std& data) const;
  bool cell_pack_addr_std(
    Ref<vm::Cell>& cell_ref, Ref<CellSlice> anycast, int workchain_id, td::BitArray<256> address
  ) const;
  bool unpack(vm::CellSlice& cs, Record_addr_var& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_addr_var& data) const;
  bool pack(vm::CellBuilder& cb, const Record_addr_var& data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_addr_var& data) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "MsgAddressInt";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return cs.bselect(2, 12);
  }
};

struct MsgAddressInt::Record_addr_std {
  typedef MsgAddressInt type_class;
  Ref<CellSlice> anycast;  // anycast : Maybe Anycast
  int workchain_id;  // workchain_id : int8
  td::BitArray<256> address;  // address : bits256
  Record_addr_std() = default;
  Record_addr_std(Ref<CellSlice> _anycast, int _workchain_id, const td::BitArray<256>& _address) :
      anycast(std::move(_anycast)), workchain_id(_workchain_id), address(_address) {
  }
};

struct MsgAddressInt::Record_addr_var {
  typedef MsgAddressInt type_class;
  Ref<CellSlice> anycast;  // anycast : Maybe Anycast
  int addr_len;  // addr_len : ## 9
  int workchain_id;  // workchain_id : int32
  Ref<td::BitString> address;  // address : bits addr_len
  Record_addr_var() = default;
  Record_addr_var(Ref<CellSlice> _anycast, int _addr_len, int _workchain_id, Ref<td::BitString> _address) :
      anycast(std::move(_anycast)), addr_len(_addr_len), workchain_id(_workchain_id), address(std::move(_address)) {
  }
};

extern const MsgAddressInt t_MsgAddressInt;

//
// headers for type `MsgAddress`
//

struct MsgAddress final : TLB_Complex {
  enum { cons2, cons1 };
  static constexpr int cons_len_exact = 0;
  struct Record_cons1 {
    typedef MsgAddress type_class;
    Ref<CellSlice> x;  // MsgAddressInt
    Record_cons1() = default;
    Record_cons1(Ref<CellSlice> _x) : x(std::move(_x)) {
    }
  };
  struct Record_cons2 {
    typedef MsgAddress type_class;
    Ref<CellSlice> x;  // MsgAddressExt
    Record_cons2() = default;
    Record_cons2(Ref<CellSlice> _x) : x(std::move(_x)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_cons1& data) const;
  bool unpack_cons1(vm::CellSlice& cs, Ref<CellSlice>& x) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_cons1& data) const;
  bool cell_unpack_cons1(Ref<vm::Cell> cell_ref, Ref<CellSlice>& x) const;
  bool pack(vm::CellBuilder& cb, const Record_cons1& data) const;
  bool pack_cons1(vm::CellBuilder& cb, Ref<CellSlice> x) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_cons1& data) const;
  bool cell_pack_cons1(Ref<vm::Cell>& cell_ref, Ref<CellSlice> x) const;
  bool unpack(vm::CellSlice& cs, Record_cons2& data) const;
  bool unpack_cons2(vm::CellSlice& cs, Ref<CellSlice>& x) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_cons2& data) const;
  bool cell_unpack_cons2(Ref<vm::Cell> cell_ref, Ref<CellSlice>& x) const;
  bool pack(vm::CellBuilder& cb, const Record_cons2& data) const;
  bool pack_cons2(vm::CellBuilder& cb, Ref<CellSlice> x) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_cons2& data) const;
  bool cell_pack_cons2(Ref<vm::Cell>& cell_ref, Ref<CellSlice> x) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "MsgAddress";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return (int)cs.prefetch_ulong(1);
  }
};

extern const MsgAddress t_MsgAddress;

//
// headers for type `InternalMsgBody`
//

struct InternalMsgBody final : TLB_Complex {
  enum { transfer_jetton, burn, transfer_nft, transfer_notification, burn_notification, internal_transfer, excesses };
  static constexpr int cons_len_exact = 32;
  static constexpr unsigned cons_tag[7] = {
    0xf8a7ea5, 0x595f07bc, 0x5fcc3d14, 0x7362d09c, 0x7bdd97de, 0x978d4519U, 0xd53276dbU
  };
  struct Record_transfer_jetton;
  struct Record_transfer_notification;
  struct Record_excesses {
    typedef InternalMsgBody type_class;
    unsigned long long query_id;  // query_id : uint64
    Record_excesses() = default;
    Record_excesses(unsigned long long _query_id) : query_id(_query_id) {
    }
  };
  struct Record_burn;
  struct Record_transfer_nft;
  struct Record_internal_transfer;
  struct Record_burn_notification;
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_transfer_jetton& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_transfer_jetton& data) const;
  bool pack(vm::CellBuilder& cb, const Record_transfer_jetton& data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_transfer_jetton& data) const;
  bool unpack(vm::CellSlice& cs, Record_transfer_notification& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_transfer_notification& data) const;
  bool pack(vm::CellBuilder& cb, const Record_transfer_notification& data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_transfer_notification& data) const;
  bool unpack(vm::CellSlice& cs, Record_excesses& data) const;
  bool unpack_excesses(vm::CellSlice& cs, unsigned long long& query_id) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_excesses& data) const;
  bool cell_unpack_excesses(Ref<vm::Cell> cell_ref, unsigned long long& query_id) const;
  bool pack(vm::CellBuilder& cb, const Record_excesses& data) const;
  bool pack_excesses(vm::CellBuilder& cb, unsigned long long query_id) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_excesses& data) const;
  bool cell_pack_excesses(Ref<vm::Cell>& cell_ref, unsigned long long query_id) const;
  bool unpack(vm::CellSlice& cs, Record_burn& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_burn& data) const;
  bool pack(vm::CellBuilder& cb, const Record_burn& data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_burn& data) const;
  bool unpack(vm::CellSlice& cs, Record_transfer_nft& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_transfer_nft& data) const;
  bool pack(vm::CellBuilder& cb, const Record_transfer_nft& data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_transfer_nft& data) const;
  bool unpack(vm::CellSlice& cs, Record_internal_transfer& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_internal_transfer& data) const;
  bool pack(vm::CellBuilder& cb, const Record_internal_transfer& data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_internal_transfer& data) const;
  bool unpack(vm::CellSlice& cs, Record_burn_notification& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_burn_notification& data) const;
  bool pack(vm::CellBuilder& cb, const Record_burn_notification& data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_burn_notification& data) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "InternalMsgBody";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return cs.bselect(6, 0x20002050c00008ULL);
  }
};

struct InternalMsgBody::Record_transfer_jetton {
  typedef InternalMsgBody type_class;
  unsigned long long query_id;  // query_id : uint64
  Ref<CellSlice> amount;  // amount : VarUInteger 16
  Ref<CellSlice> destination;  // destination : MsgAddress
  Ref<CellSlice> response_destination;  // response_destination : MsgAddress
  Ref<CellSlice> custom_payload;  // custom_payload : Maybe ^Cell
  Ref<CellSlice> forward_ton_amount;  // forward_ton_amount : VarUInteger 16
  Ref<CellSlice> forward_payload;  // forward_payload : Either Cell ^Cell
  Record_transfer_jetton() = default;
  Record_transfer_jetton(
    unsigned long long _query_id,
    Ref<CellSlice> _amount,
    Ref<CellSlice> _destination,
    Ref<CellSlice> _response_destination,
    Ref<CellSlice> _custom_payload,
    Ref<CellSlice> _forward_ton_amount,
    Ref<CellSlice> _forward_payload
  ) :
      query_id(_query_id),
      amount(std::move(_amount)),
      destination(std::move(_destination)),
      response_destination(std::move(_response_destination)),
      custom_payload(std::move(_custom_payload)),
      forward_ton_amount(std::move(_forward_ton_amount)),
      forward_payload(std::move(_forward_payload)) {
  }
};

struct InternalMsgBody::Record_transfer_notification {
  typedef InternalMsgBody type_class;
  unsigned long long query_id;  // query_id : uint64
  Ref<CellSlice> amount;  // amount : VarUInteger 16
  Ref<CellSlice> sender;  // sender : MsgAddress
  Ref<CellSlice> forward_payload;  // forward_payload : Either Cell ^Cell
  Record_transfer_notification() = default;
  Record_transfer_notification(
    unsigned long long _query_id, Ref<CellSlice> _amount, Ref<CellSlice> _sender, Ref<CellSlice> _forward_payload
  ) :
      query_id(_query_id),
      amount(std::move(_amount)),
      sender(std::move(_sender)),
      forward_payload(std::move(_forward_payload)) {
  }
};

struct InternalMsgBody::Record_burn {
  typedef InternalMsgBody type_class;
  unsigned long long query_id;  // query_id : uint64
  Ref<CellSlice> amount;  // amount : VarUInteger 16
  Ref<CellSlice> response_destination;  // response_destination : MsgAddress
  Ref<CellSlice> custom_payload;  // custom_payload : Maybe ^Cell
  Record_burn() = default;
  Record_burn(
    unsigned long long _query_id,
    Ref<CellSlice> _amount,
    Ref<CellSlice> _response_destination,
    Ref<CellSlice> _custom_payload
  ) :
      query_id(_query_id),
      amount(std::move(_amount)),
      response_destination(std::move(_response_destination)),
      custom_payload(std::move(_custom_payload)) {
  }
};

struct InternalMsgBody::Record_transfer_nft {
  typedef InternalMsgBody type_class;
  unsigned long long query_id;  // query_id : uint64
  Ref<CellSlice> new_owner;  // new_owner : MsgAddress
  Ref<CellSlice> response_destination;  // response_destination : MsgAddress
  Ref<CellSlice> custom_payload;  // custom_payload : Maybe ^Cell
  Ref<CellSlice> forward_amount;  // forward_amount : VarUInteger 16
  Ref<CellSlice> forward_payload;  // forward_payload : Either Cell ^Cell
  Record_transfer_nft() = default;
  Record_transfer_nft(
    unsigned long long _query_id,
    Ref<CellSlice> _new_owner,
    Ref<CellSlice> _response_destination,
    Ref<CellSlice> _custom_payload,
    Ref<CellSlice> _forward_amount,
    Ref<CellSlice> _forward_payload
  ) :
      query_id(_query_id),
      new_owner(std::move(_new_owner)),
      response_destination(std::move(_response_destination)),
      custom_payload(std::move(_custom_payload)),
      forward_amount(std::move(_forward_amount)),
      forward_payload(std::move(_forward_payload)) {
  }
};

struct InternalMsgBody::Record_internal_transfer {
  typedef InternalMsgBody type_class;
  unsigned long long query_id;  // query_id : uint64
  Ref<CellSlice> amount;  // amount : VarUInteger 16
  Ref<CellSlice> from;  // from : MsgAddress
  Ref<CellSlice> response_address;  // response_address : MsgAddress
  Ref<CellSlice> forward_ton_amount;  // forward_ton_amount : VarUInteger 16
  Ref<CellSlice> forward_payload;  // forward_payload : Either Cell ^Cell
  Record_internal_transfer() = default;
  Record_internal_transfer(
    unsigned long long _query_id,
    Ref<CellSlice> _amount,
    Ref<CellSlice> _from,
    Ref<CellSlice> _response_address,
    Ref<CellSlice> _forward_ton_amount,
    Ref<CellSlice> _forward_payload
  ) :
      query_id(_query_id),
      amount(std::move(_amount)),
      from(std::move(_from)),
      response_address(std::move(_response_address)),
      forward_ton_amount(std::move(_forward_ton_amount)),
      forward_payload(std::move(_forward_payload)) {
  }
};

struct InternalMsgBody::Record_burn_notification {
  typedef InternalMsgBody type_class;
  unsigned long long query_id;  // query_id : uint64
  Ref<CellSlice> amount;  // amount : VarUInteger 16
  Ref<CellSlice> sender;  // sender : MsgAddress
  Ref<CellSlice> response_destination;  // response_destination : MsgAddress
  Record_burn_notification() = default;
  Record_burn_notification(
    unsigned long long _query_id, Ref<CellSlice> _amount, Ref<CellSlice> _sender, Ref<CellSlice> _response_destination
  ) :
      query_id(_query_id),
      amount(std::move(_amount)),
      sender(std::move(_sender)),
      response_destination(std::move(_response_destination)) {
  }
};

extern const InternalMsgBody t_InternalMsgBody;

//
// headers for type `Bit`
//

struct Bit final : TLB_Complex {
  enum { bit };
  static constexpr int cons_len_exact = 0;
  struct Record {
    typedef Bit type_class;
    bool x;  // ## 1
    Record() = default;
    Record(bool _x) : x(_x) {
    }
  };
  int get_size(const vm::CellSlice& cs) const override {
    return 1;
  }
  bool skip(vm::CellSlice& cs) const override {
    return cs.advance(1);
  }
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override {
    return cs.advance(1);
  }
  bool unpack(vm::CellSlice& cs, Record& data) const;
  bool unpack_bit(vm::CellSlice& cs, bool& x) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record& data) const;
  bool cell_unpack_bit(Ref<vm::Cell> cell_ref, bool& x) const;
  bool pack(vm::CellBuilder& cb, const Record& data) const;
  bool pack_bit(vm::CellBuilder& cb, bool x) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record& data) const;
  bool cell_pack_bit(Ref<vm::Cell>& cell_ref, bool x) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "Bit";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return 0;
  }
};

extern const Bit t_Bit;

//
// headers for type `Hashmap`
//

struct Hashmap final : TLB_Complex {
  enum { hm_edge };
  static constexpr int cons_len_exact = 0;
  int m_;
  const TLB& X_;
  Hashmap(int m, const TLB& X) : m_(m), X_(X) {
  }
  struct Record;
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record& data) const;
  bool pack(vm::CellBuilder& cb, const Record& data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record& data) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "(Hashmap " << m_ << " " << X_ << ")";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return 0;
  }
};

struct Hashmap::Record {
  typedef Hashmap type_class;
  int n;  // n : #
  int l;  // l : #
  int m;  // m : #
  Ref<CellSlice> label;  // label : HmLabel ~l n
  Ref<CellSlice> node;  // node : HashmapNode m X
  Record() = default;
  Record(Ref<CellSlice> _label, Ref<CellSlice> _node) :
      n(-1), l(-1), m(-1), label(std::move(_label)), node(std::move(_node)) {
  }
};

//
// headers for type `HashmapNode`
//

struct HashmapNode final : TLB_Complex {
  enum { hmn_leaf, hmn_fork };
  static constexpr int cons_len_exact = 0;
  int m_;
  const TLB& X_;
  HashmapNode(int m, const TLB& X) : m_(m), X_(X) {
  }
  struct Record_hmn_leaf {
    typedef HashmapNode type_class;
    Ref<CellSlice> value;  // value : X
    Record_hmn_leaf() = default;
    Record_hmn_leaf(Ref<CellSlice> _value) : value(std::move(_value)) {
    }
  };
  struct Record_hmn_fork;
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_hmn_leaf& data) const;
  bool unpack_hmn_leaf(vm::CellSlice& cs, Ref<CellSlice>& value) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_hmn_leaf& data) const;
  bool cell_unpack_hmn_leaf(Ref<vm::Cell> cell_ref, Ref<CellSlice>& value) const;
  bool pack(vm::CellBuilder& cb, const Record_hmn_leaf& data) const;
  bool pack_hmn_leaf(vm::CellBuilder& cb, Ref<CellSlice> value) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_hmn_leaf& data) const;
  bool cell_pack_hmn_leaf(Ref<vm::Cell>& cell_ref, Ref<CellSlice> value) const;
  bool unpack(vm::CellSlice& cs, Record_hmn_fork& data) const;
  bool unpack_hmn_fork(vm::CellSlice& cs, int& n, Ref<Cell>& left, Ref<Cell>& right) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_hmn_fork& data) const;
  bool cell_unpack_hmn_fork(Ref<vm::Cell> cell_ref, int& n, Ref<Cell>& left, Ref<Cell>& right) const;
  bool pack(vm::CellBuilder& cb, const Record_hmn_fork& data) const;
  bool pack_hmn_fork(vm::CellBuilder& cb, Ref<Cell> left, Ref<Cell> right) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_hmn_fork& data) const;
  bool cell_pack_hmn_fork(Ref<vm::Cell>& cell_ref, Ref<Cell> left, Ref<Cell> right) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "(HashmapNode " << m_ << " " << X_ << ")";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override;
};

struct HashmapNode::Record_hmn_fork {
  typedef HashmapNode type_class;
  int n;  // n : #
  Ref<Cell> left;  // left : ^(Hashmap n X)
  Ref<Cell> right;  // right : ^(Hashmap n X)
  Record_hmn_fork() = default;
  Record_hmn_fork(Ref<Cell> _left, Ref<Cell> _right) : n(-1), left(std::move(_left)), right(std::move(_right)) {
  }
};

//
// headers for type `HmLabel`
//

struct HmLabel final : TLB_Complex {
  enum { hml_short, hml_long, hml_same };
  static constexpr char cons_len[3] = {1, 2, 2};
  static constexpr unsigned char cons_tag[3] = {0, 2, 3};
  int n_;
  HmLabel(int n) : n_(n) {
  }
  struct Record_hml_short;
  struct Record_hml_long;
  struct Record_hml_same;
  bool skip(vm::CellSlice& cs) const override;
  bool skip(vm::CellSlice& cs, int& m_) const;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak, int& m_) const;
  bool fetch_to(vm::CellSlice& cs, Ref<vm::CellSlice>& res, int& m_) const;
  bool unpack(vm::CellSlice& cs, Record_hml_short& data, int& m_) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_hml_short& data, int& m_) const;
  bool pack(vm::CellBuilder& cb, const Record_hml_short& data, int& m_) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_hml_short& data, int& m_) const;
  bool unpack(vm::CellSlice& cs, Record_hml_long& data, int& m_) const;
  bool unpack_hml_long(vm::CellSlice& cs, int& m, int& n, Ref<td::BitString>& s, int& m_) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_hml_long& data, int& m_) const;
  bool cell_unpack_hml_long(Ref<vm::Cell> cell_ref, int& m, int& n, Ref<td::BitString>& s, int& m_) const;
  bool pack(vm::CellBuilder& cb, const Record_hml_long& data, int& m_) const;
  bool pack_hml_long(vm::CellBuilder& cb, int n, Ref<td::BitString> s, int& m_) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_hml_long& data, int& m_) const;
  bool cell_pack_hml_long(Ref<vm::Cell>& cell_ref, int n, Ref<td::BitString> s, int& m_) const;
  bool unpack(vm::CellSlice& cs, Record_hml_same& data, int& m_) const;
  bool unpack_hml_same(vm::CellSlice& cs, int& m, bool& v, int& n, int& m_) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_hml_same& data, int& m_) const;
  bool cell_unpack_hml_same(Ref<vm::Cell> cell_ref, int& m, bool& v, int& n, int& m_) const;
  bool pack(vm::CellBuilder& cb, const Record_hml_same& data, int& m_) const;
  bool pack_hml_same(vm::CellBuilder& cb, bool v, int n, int& m_) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_hml_same& data, int& m_) const;
  bool cell_pack_hml_same(Ref<vm::Cell>& cell_ref, bool v, int n, int& m_) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs, int& m_) const;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "(HmLabel ~m_ " << n_ << ")";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return cs.bselect(2, 13);
  }
};

struct HmLabel::Record_hml_short {
  typedef HmLabel type_class;
  int m;  // m : #
  int n;  // n : #
  Ref<CellSlice> len;  // len : Unary ~n
  Ref<td::BitString> s;  // s : n * Bit
  Record_hml_short() = default;
  Record_hml_short(Ref<CellSlice> _len, Ref<td::BitString> _s) : m(-1), n(-1), len(std::move(_len)), s(std::move(_s)) {
  }
};

struct HmLabel::Record_hml_long {
  typedef HmLabel type_class;
  int m;  // m : #
  int n;  // n : #<= m
  Ref<td::BitString> s;  // s : n * Bit
  Record_hml_long() = default;
  Record_hml_long(int _n, Ref<td::BitString> _s) : m(-1), n(_n), s(std::move(_s)) {
  }
};

struct HmLabel::Record_hml_same {
  typedef HmLabel type_class;
  int m;  // m : #
  bool v;  // v : Bit
  int n;  // n : #<= m
  Record_hml_same() = default;
  Record_hml_same(bool _v, int _n) : m(-1), v(_v), n(_n) {
  }
};

//
// headers for type `Unary`
//

struct Unary final : TLB_Complex {
  enum { unary_zero, unary_succ };
  static constexpr int cons_len_exact = 1;
  struct Record_unary_zero {
    typedef Unary type_class;
  };
  struct Record_unary_succ {
    typedef Unary type_class;
    int n;  // n : #
    Ref<CellSlice> x;  // x : Unary ~n
    Record_unary_succ() = default;
    Record_unary_succ(Ref<CellSlice> _x) : n(-1), x(std::move(_x)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool skip(vm::CellSlice& cs, int& m_) const;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak, int& m_) const;
  bool fetch_to(vm::CellSlice& cs, Ref<vm::CellSlice>& res, int& m_) const;
  bool unpack(vm::CellSlice& cs, Record_unary_zero& data, int& m_) const;
  bool unpack_unary_zero(vm::CellSlice& cs, int& m_) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_unary_zero& data, int& m_) const;
  bool cell_unpack_unary_zero(Ref<vm::Cell> cell_ref, int& m_) const;
  bool pack(vm::CellBuilder& cb, const Record_unary_zero& data, int& m_) const;
  bool pack_unary_zero(vm::CellBuilder& cb, int& m_) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_unary_zero& data, int& m_) const;
  bool cell_pack_unary_zero(Ref<vm::Cell>& cell_ref, int& m_) const;
  bool unpack(vm::CellSlice& cs, Record_unary_succ& data, int& m_) const;
  bool unpack_unary_succ(vm::CellSlice& cs, int& n, Ref<CellSlice>& x, int& m_) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_unary_succ& data, int& m_) const;
  bool cell_unpack_unary_succ(Ref<vm::Cell> cell_ref, int& n, Ref<CellSlice>& x, int& m_) const;
  bool pack(vm::CellBuilder& cb, const Record_unary_succ& data, int& m_) const;
  bool pack_unary_succ(vm::CellBuilder& cb, Ref<CellSlice> x, int& m_) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_unary_succ& data, int& m_) const;
  bool cell_pack_unary_succ(Ref<vm::Cell>& cell_ref, Ref<CellSlice> x, int& m_) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs, int& m_) const;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "(Unary ~m_)";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return (int)cs.prefetch_ulong(1);
  }
};

extern const Unary t_Unary;

//
// headers for type `HashmapE`
//

struct HashmapE final : TLB_Complex {
  enum { hme_empty, hme_root };
  static constexpr int cons_len_exact = 1;
  int m_;
  const TLB& X_;
  HashmapE(int m, const TLB& X) : m_(m), X_(X) {
  }
  struct Record_hme_empty {
    typedef HashmapE type_class;
  };
  struct Record_hme_root {
    typedef HashmapE type_class;
    int n;  // n : #
    Ref<Cell> root;  // root : ^(Hashmap n X)
    Record_hme_root() = default;
    Record_hme_root(Ref<Cell> _root) : n(-1), root(std::move(_root)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_hme_empty& data) const;
  bool unpack_hme_empty(vm::CellSlice& cs) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_hme_empty& data) const;
  bool cell_unpack_hme_empty(Ref<vm::Cell> cell_ref) const;
  bool pack(vm::CellBuilder& cb, const Record_hme_empty& data) const;
  bool pack_hme_empty(vm::CellBuilder& cb) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_hme_empty& data) const;
  bool cell_pack_hme_empty(Ref<vm::Cell>& cell_ref) const;
  bool unpack(vm::CellSlice& cs, Record_hme_root& data) const;
  bool unpack_hme_root(vm::CellSlice& cs, int& n, Ref<Cell>& root) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_hme_root& data) const;
  bool cell_unpack_hme_root(Ref<vm::Cell> cell_ref, int& n, Ref<Cell>& root) const;
  bool pack(vm::CellBuilder& cb, const Record_hme_root& data) const;
  bool pack_hme_root(vm::CellBuilder& cb, Ref<Cell> root) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_hme_root& data) const;
  bool cell_pack_hme_root(Ref<vm::Cell>& cell_ref, Ref<Cell> root) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "(HashmapE " << m_ << " " << X_ << ")";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return (int)cs.prefetch_ulong(1);
  }
};

//
// headers for type `ChunkedData`
//

struct ChunkedData final : TLB_Complex {
  enum { chunked_data };
  static constexpr int cons_len_exact = 0;
  struct Record {
    typedef ChunkedData type_class;
    Ref<CellSlice> data;  // data : HashmapE 32 ^Cell
    Record() = default;
    Record(Ref<CellSlice> _data) : data(std::move(_data)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record& data) const;
  bool unpack_chunked_data(vm::CellSlice& cs, Ref<CellSlice>& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record& data) const;
  bool cell_unpack_chunked_data(Ref<vm::Cell> cell_ref, Ref<CellSlice>& data) const;
  bool pack(vm::CellBuilder& cb, const Record& data) const;
  bool pack_chunked_data(vm::CellBuilder& cb, Ref<CellSlice> data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record& data) const;
  bool cell_pack_chunked_data(Ref<vm::Cell>& cell_ref, Ref<CellSlice> data) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "ChunkedData";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return 0;
  }
};

extern const ChunkedData t_ChunkedData;

//
// headers for type `Text`
//

struct Text final : TLB_Complex {
  enum { text };
  static constexpr int cons_len_exact = 0;
  struct Record {
    typedef Text type_class;
    Ref<CellSlice> data;  // data : Cell
    Record() = default;
    Record(Ref<CellSlice> _data) : data(std::move(_data)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record& data) const;
  bool unpack_text(vm::CellSlice& cs, Ref<CellSlice>& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record& data) const;
  bool cell_unpack_text(Ref<vm::Cell> cell_ref, Ref<CellSlice>& data) const;
  bool pack(vm::CellBuilder& cb, const Record& data) const;
  bool pack_text(vm::CellBuilder& cb, Ref<CellSlice> data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record& data) const;
  bool cell_pack_text(Ref<vm::Cell>& cell_ref, Ref<CellSlice> data) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "Text";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return 0;
  }
};

extern const Text t_Text;

//
// headers for type `ContentData`
//

struct ContentData final : TLB_Complex {
  enum { snake, chunks };
  static constexpr int cons_len_exact = 8;
  struct Record_snake {
    typedef ContentData type_class;
    Ref<CellSlice> data;  // data : Cell
    Record_snake() = default;
    Record_snake(Ref<CellSlice> _data) : data(std::move(_data)) {
    }
  };
  struct Record_chunks {
    typedef ContentData type_class;
    Ref<CellSlice> data;  // data : ChunkedData
    Record_chunks() = default;
    Record_chunks(Ref<CellSlice> _data) : data(std::move(_data)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_snake& data) const;
  bool unpack_snake(vm::CellSlice& cs, Ref<CellSlice>& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_snake& data) const;
  bool cell_unpack_snake(Ref<vm::Cell> cell_ref, Ref<CellSlice>& data) const;
  bool pack(vm::CellBuilder& cb, const Record_snake& data) const;
  bool pack_snake(vm::CellBuilder& cb, Ref<CellSlice> data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_snake& data) const;
  bool cell_pack_snake(Ref<vm::Cell>& cell_ref, Ref<CellSlice> data) const;
  bool unpack(vm::CellSlice& cs, Record_chunks& data) const;
  bool unpack_chunks(vm::CellSlice& cs, Ref<CellSlice>& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_chunks& data) const;
  bool cell_unpack_chunks(Ref<vm::Cell> cell_ref, Ref<CellSlice>& data) const;
  bool pack(vm::CellBuilder& cb, const Record_chunks& data) const;
  bool pack_chunks(vm::CellBuilder& cb, Ref<CellSlice> data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_chunks& data) const;
  bool cell_pack_chunks(Ref<vm::Cell>& cell_ref, Ref<CellSlice> data) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "ContentData";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override;
};

extern const ContentData t_ContentData;

//
// headers for type `FullContent`
//

struct FullContent final : TLB_Complex {
  enum { onchain, offchain };
  static constexpr int cons_len_exact = 8;
  struct Record_onchain {
    typedef FullContent type_class;
    Ref<CellSlice> data;  // data : HashmapE 256 ^ContentData
    Record_onchain() = default;
    Record_onchain(Ref<CellSlice> _data) : data(std::move(_data)) {
    }
  };
  struct Record_offchain {
    typedef FullContent type_class;
    Ref<CellSlice> uri;  // uri : Text
    Record_offchain() = default;
    Record_offchain(Ref<CellSlice> _uri) : uri(std::move(_uri)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_onchain& data) const;
  bool unpack_onchain(vm::CellSlice& cs, Ref<CellSlice>& data) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_onchain& data) const;
  bool cell_unpack_onchain(Ref<vm::Cell> cell_ref, Ref<CellSlice>& data) const;
  bool pack(vm::CellBuilder& cb, const Record_onchain& data) const;
  bool pack_onchain(vm::CellBuilder& cb, Ref<CellSlice> data) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_onchain& data) const;
  bool cell_pack_onchain(Ref<vm::Cell>& cell_ref, Ref<CellSlice> data) const;
  bool unpack(vm::CellSlice& cs, Record_offchain& data) const;
  bool unpack_offchain(vm::CellSlice& cs, Ref<CellSlice>& uri) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_offchain& data) const;
  bool cell_unpack_offchain(Ref<vm::Cell> cell_ref, Ref<CellSlice>& uri) const;
  bool pack(vm::CellBuilder& cb, const Record_offchain& data) const;
  bool pack_offchain(vm::CellBuilder& cb, Ref<CellSlice> uri) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_offchain& data) const;
  bool cell_pack_offchain(Ref<vm::Cell>& cell_ref, Ref<CellSlice> uri) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "FullContent";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override;
};

extern const FullContent t_FullContent;

//
// headers for type `Protocol`
//

struct Protocol final : TLB_Complex {
  enum { proto_http };
  static constexpr int cons_len_exact = 16;
  static constexpr unsigned short cons_tag[1] = {0x4854};
  struct Record {
    typedef Protocol type_class;
  };
  int get_size(const vm::CellSlice& cs) const override {
    return 16;
  }
  bool skip(vm::CellSlice& cs) const override {
    return cs.advance(16);
  }
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool fetch_enum_to(vm::CellSlice& cs, char& value) const;
  bool store_enum_from(vm::CellBuilder& cb, int value) const;
  bool unpack(vm::CellSlice& cs, Record& data) const;
  bool unpack_proto_http(vm::CellSlice& cs) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record& data) const;
  bool cell_unpack_proto_http(Ref<vm::Cell> cell_ref) const;
  bool pack(vm::CellBuilder& cb, const Record& data) const;
  bool pack_proto_http(vm::CellBuilder& cb) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record& data) const;
  bool cell_pack_proto_http(Ref<vm::Cell>& cell_ref) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "Protocol";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return 0;
  }
};

extern const Protocol t_Protocol;

//
// headers for type `ProtoList`
//

struct ProtoList final : TLB_Complex {
  enum { proto_list_nil, proto_list_next };
  static constexpr int cons_len_exact = 1;
  struct Record_proto_list_nil {
    typedef ProtoList type_class;
  };
  struct Record_proto_list_next {
    typedef ProtoList type_class;
    char head;  // head : Protocol
    Ref<CellSlice> tail;  // tail : ProtoList
    Record_proto_list_next() = default;
    Record_proto_list_next(char _head, Ref<CellSlice> _tail) : head(_head), tail(std::move(_tail)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_proto_list_nil& data) const;
  bool unpack_proto_list_nil(vm::CellSlice& cs) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_proto_list_nil& data) const;
  bool cell_unpack_proto_list_nil(Ref<vm::Cell> cell_ref) const;
  bool pack(vm::CellBuilder& cb, const Record_proto_list_nil& data) const;
  bool pack_proto_list_nil(vm::CellBuilder& cb) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_proto_list_nil& data) const;
  bool cell_pack_proto_list_nil(Ref<vm::Cell>& cell_ref) const;
  bool unpack(vm::CellSlice& cs, Record_proto_list_next& data) const;
  bool unpack_proto_list_next(vm::CellSlice& cs, char& head, Ref<CellSlice>& tail) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_proto_list_next& data) const;
  bool cell_unpack_proto_list_next(Ref<vm::Cell> cell_ref, char& head, Ref<CellSlice>& tail) const;
  bool pack(vm::CellBuilder& cb, const Record_proto_list_next& data) const;
  bool pack_proto_list_next(vm::CellBuilder& cb, char head, Ref<CellSlice> tail) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_proto_list_next& data) const;
  bool cell_pack_proto_list_next(Ref<vm::Cell>& cell_ref, char head, Ref<CellSlice> tail) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "ProtoList";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return (int)cs.prefetch_ulong(1);
  }
};

extern const ProtoList t_ProtoList;

//
// headers for type `SmcCapability`
//

struct SmcCapability final : TLB_Complex {
  enum { cap_is_wallet };
  static constexpr int cons_len_exact = 16;
  static constexpr unsigned short cons_tag[1] = {0x2177};
  struct Record {
    typedef SmcCapability type_class;
  };
  int get_size(const vm::CellSlice& cs) const override {
    return 16;
  }
  bool skip(vm::CellSlice& cs) const override {
    return cs.advance(16);
  }
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool fetch_enum_to(vm::CellSlice& cs, char& value) const;
  bool store_enum_from(vm::CellBuilder& cb, int value) const;
  bool unpack(vm::CellSlice& cs, Record& data) const;
  bool unpack_cap_is_wallet(vm::CellSlice& cs) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record& data) const;
  bool cell_unpack_cap_is_wallet(Ref<vm::Cell> cell_ref) const;
  bool pack(vm::CellBuilder& cb, const Record& data) const;
  bool pack_cap_is_wallet(vm::CellBuilder& cb) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record& data) const;
  bool cell_pack_cap_is_wallet(Ref<vm::Cell>& cell_ref) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "SmcCapability";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return 0;
  }
};

extern const SmcCapability t_SmcCapability;

//
// headers for type `SmcCapList`
//

struct SmcCapList final : TLB_Complex {
  enum { cap_list_nil, cap_list_next };
  static constexpr int cons_len_exact = 1;
  struct Record_cap_list_nil {
    typedef SmcCapList type_class;
  };
  struct Record_cap_list_next {
    typedef SmcCapList type_class;
    char head;  // head : SmcCapability
    Ref<CellSlice> tail;  // tail : SmcCapList
    Record_cap_list_next() = default;
    Record_cap_list_next(char _head, Ref<CellSlice> _tail) : head(_head), tail(std::move(_tail)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_cap_list_nil& data) const;
  bool unpack_cap_list_nil(vm::CellSlice& cs) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_cap_list_nil& data) const;
  bool cell_unpack_cap_list_nil(Ref<vm::Cell> cell_ref) const;
  bool pack(vm::CellBuilder& cb, const Record_cap_list_nil& data) const;
  bool pack_cap_list_nil(vm::CellBuilder& cb) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_cap_list_nil& data) const;
  bool cell_pack_cap_list_nil(Ref<vm::Cell>& cell_ref) const;
  bool unpack(vm::CellSlice& cs, Record_cap_list_next& data) const;
  bool unpack_cap_list_next(vm::CellSlice& cs, char& head, Ref<CellSlice>& tail) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_cap_list_next& data) const;
  bool cell_unpack_cap_list_next(Ref<vm::Cell> cell_ref, char& head, Ref<CellSlice>& tail) const;
  bool pack(vm::CellBuilder& cb, const Record_cap_list_next& data) const;
  bool pack_cap_list_next(vm::CellBuilder& cb, char head, Ref<CellSlice> tail) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_cap_list_next& data) const;
  bool cell_pack_cap_list_next(Ref<vm::Cell>& cell_ref, char head, Ref<CellSlice> tail) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "SmcCapList";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return (int)cs.prefetch_ulong(1);
  }
};

extern const SmcCapList t_SmcCapList;

//
// headers for type `DNSRecord`
//

struct DNSRecord final : TLB_Complex {
  enum { dns_storage_address, dns_smc_address, dns_adnl_address, dns_next_resolver };
  static constexpr int cons_len_exact = 16;
  static constexpr unsigned short cons_tag[4] = {0x7473, 0x9fd3, 0xad01, 0xba93};
  struct Record_dns_smc_address;
  struct Record_dns_next_resolver {
    typedef DNSRecord type_class;
    Ref<CellSlice> resolver;  // resolver : MsgAddressInt
    Record_dns_next_resolver() = default;
    Record_dns_next_resolver(Ref<CellSlice> _resolver) : resolver(std::move(_resolver)) {
    }
  };
  struct Record_dns_adnl_address;
  struct Record_dns_storage_address {
    typedef DNSRecord type_class;
    td::BitArray<256> bag_id;  // bag_id : bits256
    Record_dns_storage_address() = default;
    Record_dns_storage_address(const td::BitArray<256>& _bag_id) : bag_id(_bag_id) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record_dns_smc_address& data) const;
  bool unpack_dns_smc_address(vm::CellSlice& cs, Ref<CellSlice>& smc_addr, int& flags, Ref<CellSlice>& cap_list) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_dns_smc_address& data) const;
  bool cell_unpack_dns_smc_address(
    Ref<vm::Cell> cell_ref, Ref<CellSlice>& smc_addr, int& flags, Ref<CellSlice>& cap_list
  ) const;
  bool pack(vm::CellBuilder& cb, const Record_dns_smc_address& data) const;
  bool pack_dns_smc_address(vm::CellBuilder& cb, Ref<CellSlice> smc_addr, int flags, Ref<CellSlice> cap_list) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_dns_smc_address& data) const;
  bool cell_pack_dns_smc_address(
    Ref<vm::Cell>& cell_ref, Ref<CellSlice> smc_addr, int flags, Ref<CellSlice> cap_list
  ) const;
  bool unpack(vm::CellSlice& cs, Record_dns_next_resolver& data) const;
  bool unpack_dns_next_resolver(vm::CellSlice& cs, Ref<CellSlice>& resolver) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_dns_next_resolver& data) const;
  bool cell_unpack_dns_next_resolver(Ref<vm::Cell> cell_ref, Ref<CellSlice>& resolver) const;
  bool pack(vm::CellBuilder& cb, const Record_dns_next_resolver& data) const;
  bool pack_dns_next_resolver(vm::CellBuilder& cb, Ref<CellSlice> resolver) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_dns_next_resolver& data) const;
  bool cell_pack_dns_next_resolver(Ref<vm::Cell>& cell_ref, Ref<CellSlice> resolver) const;
  bool unpack(vm::CellSlice& cs, Record_dns_adnl_address& data) const;
  bool unpack_dns_adnl_address(
    vm::CellSlice& cs, td::BitArray<256>& adnl_addr, int& flags, Ref<CellSlice>& proto_list
  ) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_dns_adnl_address& data) const;
  bool cell_unpack_dns_adnl_address(
    Ref<vm::Cell> cell_ref, td::BitArray<256>& adnl_addr, int& flags, Ref<CellSlice>& proto_list
  ) const;
  bool pack(vm::CellBuilder& cb, const Record_dns_adnl_address& data) const;
  bool pack_dns_adnl_address(
    vm::CellBuilder& cb, td::BitArray<256> adnl_addr, int flags, Ref<CellSlice> proto_list
  ) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_dns_adnl_address& data) const;
  bool cell_pack_dns_adnl_address(
    Ref<vm::Cell>& cell_ref, td::BitArray<256> adnl_addr, int flags, Ref<CellSlice> proto_list
  ) const;
  bool unpack(vm::CellSlice& cs, Record_dns_storage_address& data) const;
  bool unpack_dns_storage_address(vm::CellSlice& cs, td::BitArray<256>& bag_id) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record_dns_storage_address& data) const;
  bool cell_unpack_dns_storage_address(Ref<vm::Cell> cell_ref, td::BitArray<256>& bag_id) const;
  bool pack(vm::CellBuilder& cb, const Record_dns_storage_address& data) const;
  bool pack_dns_storage_address(vm::CellBuilder& cb, td::BitArray<256> bag_id) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record_dns_storage_address& data) const;
  bool cell_pack_dns_storage_address(Ref<vm::Cell>& cell_ref, td::BitArray<256> bag_id) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "DNSRecord";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return cs.bselect(4, 0xe80);
  }
};

struct DNSRecord::Record_dns_smc_address {
  typedef DNSRecord type_class;
  Ref<CellSlice> smc_addr;  // smc_addr : MsgAddressInt
  int flags;  // flags : ## 8
  Ref<CellSlice> cap_list;  // cap_list : flags.0?SmcCapList
  Record_dns_smc_address() = default;
  Record_dns_smc_address(Ref<CellSlice> _smc_addr, int _flags, Ref<CellSlice> _cap_list) :
      smc_addr(std::move(_smc_addr)), flags(_flags), cap_list(std::move(_cap_list)) {
  }
};

struct DNSRecord::Record_dns_adnl_address {
  typedef DNSRecord type_class;
  td::BitArray<256> adnl_addr;  // adnl_addr : bits256
  int flags;  // flags : ## 8
  Ref<CellSlice> proto_list;  // proto_list : flags.0?ProtoList
  Record_dns_adnl_address() = default;
  Record_dns_adnl_address(const td::BitArray<256>& _adnl_addr, int _flags, Ref<CellSlice> _proto_list) :
      adnl_addr(_adnl_addr), flags(_flags), proto_list(std::move(_proto_list)) {
  }
};

extern const DNSRecord t_DNSRecord;

//
// headers for type `DNS_RecordSet`
//

struct DNS_RecordSet final : TLB_Complex {
  enum { cons1 };
  static constexpr int cons_len_exact = 0;
  struct Record {
    typedef DNS_RecordSet type_class;
    Ref<CellSlice> x;  // HashmapE 256 ^DNSRecord
    Record() = default;
    Record(Ref<CellSlice> _x) : x(std::move(_x)) {
    }
  };
  bool skip(vm::CellSlice& cs) const override;
  bool validate_skip(int* ops, vm::CellSlice& cs, bool weak = false) const override;
  bool unpack(vm::CellSlice& cs, Record& data) const;
  bool unpack_cons1(vm::CellSlice& cs, Ref<CellSlice>& x) const;
  bool cell_unpack(Ref<vm::Cell> cell_ref, Record& data) const;
  bool cell_unpack_cons1(Ref<vm::Cell> cell_ref, Ref<CellSlice>& x) const;
  bool pack(vm::CellBuilder& cb, const Record& data) const;
  bool pack_cons1(vm::CellBuilder& cb, Ref<CellSlice> x) const;
  bool cell_pack(Ref<vm::Cell>& cell_ref, const Record& data) const;
  bool cell_pack_cons1(Ref<vm::Cell>& cell_ref, Ref<CellSlice> x) const;
  bool print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const override;
  std::ostream& print_type(std::ostream& os) const override {
    return os << "DNS_RecordSet";
  }
  int check_tag(const vm::CellSlice& cs) const override;
  int get_tag(const vm::CellSlice& cs) const override {
    return 0;
  }
};

extern const DNS_RecordSet t_DNS_RecordSet;

// declarations of constant types used

// ## 9
extern const NatWidth t_natwidth_9;
// #<= 30
extern const NatLeq t_natleq_30;
// Maybe Anycast
extern const Maybe t_Maybe_Anycast;
// int8
extern const Int t_int8;
// bits256
extern const Bits t_bits256;
// int32
extern const Int t_int32;
// uint64
extern const UInt t_uint64;
// VarUInteger 16
extern const VarUInteger t_VarUInteger_16;
// Maybe ^Cell
extern const Maybe t_Maybe_Ref_Cell;
// Either Cell ^Cell
extern const Either t_Either_Cell_Ref_Cell;
// ## 1
extern const NatWidth t_natwidth_1;
// HashmapE 32 ^Cell
extern const HashmapE t_HashmapE_32_Ref_Cell;
// ^ContentData
extern const RefT t_Ref_ContentData;
// HashmapE 256 ^ContentData
extern const HashmapE t_HashmapE_256_Ref_ContentData;
// ## 8
extern const NatWidth t_natwidth_8;
// ^DNSRecord
extern const RefT t_Ref_DNSRecord;
// HashmapE 256 ^DNSRecord
extern const HashmapE t_HashmapE_256_Ref_DNSRecord;

// declaration of type name registration function
extern bool register_simple_types(std::function<bool(const char*, const TLB*)> func);

}  // namespace gen

}  // namespace tokens
