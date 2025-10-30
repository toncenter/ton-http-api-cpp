#include "tokens-tlb.h"
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
using vm::CellSlice;
using vm::Cell;
using td::RefInt256;

//
// code for type `Maybe`
//

int Maybe::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case nothing:
    return cs.have(1) ? nothing : -1;
  case just:
    return cs.have(1) ? just : -1;
  }
  return -1;
}

bool Maybe::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case nothing:
    return cs.advance(1);
  case just:
    return cs.advance(1)
        && X_.skip(cs);
  }
  return false;
}

bool Maybe::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case nothing:
    return cs.advance(1);
  case just:
    return cs.advance(1)
        && X_.validate_skip(ops, cs, weak);
  }
  return false;
}

bool Maybe::unpack(vm::CellSlice& cs, Maybe::Record_nothing& data) const {
  return cs.fetch_ulong(1) == 0;
}

bool Maybe::unpack_nothing(vm::CellSlice& cs) const {
  return cs.fetch_ulong(1) == 0;
}

bool Maybe::cell_unpack(Ref<vm::Cell> cell_ref, Maybe::Record_nothing& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool Maybe::cell_unpack_nothing(Ref<vm::Cell> cell_ref) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_nothing(cs) && cs.empty_ext();
}

bool Maybe::unpack(vm::CellSlice& cs, Maybe::Record_just& data) const {
  return cs.fetch_ulong(1) == 1
      && X_.fetch_to(cs, data.value);
}

bool Maybe::unpack_just(vm::CellSlice& cs, Ref<CellSlice>& value) const {
  return cs.fetch_ulong(1) == 1
      && X_.fetch_to(cs, value);
}

bool Maybe::cell_unpack(Ref<vm::Cell> cell_ref, Maybe::Record_just& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool Maybe::cell_unpack_just(Ref<vm::Cell> cell_ref, Ref<CellSlice>& value) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_just(cs, value) && cs.empty_ext();
}

bool Maybe::pack(vm::CellBuilder& cb, const Maybe::Record_nothing& data) const {
  return cb.store_long_bool(0, 1);
}

bool Maybe::pack_nothing(vm::CellBuilder& cb) const {
  return cb.store_long_bool(0, 1);
}

bool Maybe::cell_pack(Ref<vm::Cell>& cell_ref, const Maybe::Record_nothing& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool Maybe::cell_pack_nothing(Ref<vm::Cell>& cell_ref) const {
  vm::CellBuilder cb;
  return pack_nothing(cb) && std::move(cb).finalize_to(cell_ref);
}

bool Maybe::pack(vm::CellBuilder& cb, const Maybe::Record_just& data) const {
  return cb.store_long_bool(1, 1)
      && X_.store_from(cb, data.value);
}

bool Maybe::pack_just(vm::CellBuilder& cb, Ref<CellSlice> value) const {
  return cb.store_long_bool(1, 1)
      && X_.store_from(cb, value);
}

bool Maybe::cell_pack(Ref<vm::Cell>& cell_ref, const Maybe::Record_just& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool Maybe::cell_pack_just(Ref<vm::Cell>& cell_ref, Ref<CellSlice> value) const {
  vm::CellBuilder cb;
  return pack_just(cb, std::move(value)) && std::move(cb).finalize_to(cell_ref);
}

bool Maybe::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case nothing:
    return cs.advance(1)
        && pp.cons("nothing");
  case just:
    return cs.advance(1)
        && pp.open("just")
        && pp.field("value")
        && X_.print_skip(pp, cs)
        && pp.close();
  }
  return pp.fail("unknown constructor for Maybe");
}


//
// code for type `Either`
//

int Either::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case left:
    return cs.have(1) ? left : -1;
  case right:
    return cs.have(1) ? right : -1;
  }
  return -1;
}

bool Either::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case left:
    return cs.advance(1)
        && X_.skip(cs);
  case right:
    return cs.advance(1)
        && Y_.skip(cs);
  }
  return false;
}

bool Either::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case left:
    return cs.advance(1)
        && X_.validate_skip(ops, cs, weak);
  case right:
    return cs.advance(1)
        && Y_.validate_skip(ops, cs, weak);
  }
  return false;
}

bool Either::unpack(vm::CellSlice& cs, Either::Record_left& data) const {
  return cs.fetch_ulong(1) == 0
      && X_.fetch_to(cs, data.value);
}

bool Either::unpack_left(vm::CellSlice& cs, Ref<CellSlice>& value) const {
  return cs.fetch_ulong(1) == 0
      && X_.fetch_to(cs, value);
}

bool Either::cell_unpack(Ref<vm::Cell> cell_ref, Either::Record_left& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool Either::cell_unpack_left(Ref<vm::Cell> cell_ref, Ref<CellSlice>& value) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_left(cs, value) && cs.empty_ext();
}

bool Either::unpack(vm::CellSlice& cs, Either::Record_right& data) const {
  return cs.fetch_ulong(1) == 1
      && Y_.fetch_to(cs, data.value);
}

bool Either::unpack_right(vm::CellSlice& cs, Ref<CellSlice>& value) const {
  return cs.fetch_ulong(1) == 1
      && Y_.fetch_to(cs, value);
}

bool Either::cell_unpack(Ref<vm::Cell> cell_ref, Either::Record_right& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool Either::cell_unpack_right(Ref<vm::Cell> cell_ref, Ref<CellSlice>& value) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_right(cs, value) && cs.empty_ext();
}

bool Either::pack(vm::CellBuilder& cb, const Either::Record_left& data) const {
  return cb.store_long_bool(0, 1)
      && X_.store_from(cb, data.value);
}

bool Either::pack_left(vm::CellBuilder& cb, Ref<CellSlice> value) const {
  return cb.store_long_bool(0, 1)
      && X_.store_from(cb, value);
}

bool Either::cell_pack(Ref<vm::Cell>& cell_ref, const Either::Record_left& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool Either::cell_pack_left(Ref<vm::Cell>& cell_ref, Ref<CellSlice> value) const {
  vm::CellBuilder cb;
  return pack_left(cb, std::move(value)) && std::move(cb).finalize_to(cell_ref);
}

bool Either::pack(vm::CellBuilder& cb, const Either::Record_right& data) const {
  return cb.store_long_bool(1, 1)
      && Y_.store_from(cb, data.value);
}

bool Either::pack_right(vm::CellBuilder& cb, Ref<CellSlice> value) const {
  return cb.store_long_bool(1, 1)
      && Y_.store_from(cb, value);
}

bool Either::cell_pack(Ref<vm::Cell>& cell_ref, const Either::Record_right& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool Either::cell_pack_right(Ref<vm::Cell>& cell_ref, Ref<CellSlice> value) const {
  vm::CellBuilder cb;
  return pack_right(cb, std::move(value)) && std::move(cb).finalize_to(cell_ref);
}

bool Either::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case left:
    return cs.advance(1)
        && pp.open("left")
        && pp.field("value")
        && X_.print_skip(pp, cs)
        && pp.close();
  case right:
    return cs.advance(1)
        && pp.open("right")
        && pp.field("value")
        && Y_.print_skip(pp, cs)
        && pp.close();
  }
  return pp.fail("unknown constructor for Either");
}


//
// code for type `VarUInteger`
//

int VarUInteger::check_tag(const vm::CellSlice& cs) const {
  return var_uint;
}

bool VarUInteger::skip(vm::CellSlice& cs) const {
  int len;
  return cs.fetch_uint_less(m_, len)
      && cs.advance(8 * len);
}

bool VarUInteger::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  int len;
  return cs.fetch_uint_less(m_, len)
      && cs.advance(8 * len);
}

bool VarUInteger::unpack(vm::CellSlice& cs, VarUInteger::Record& data) const {
  return (data.n = m_) >= 0
      && cs.fetch_uint_less(m_, data.len)
      && cs.fetch_uint256_to(8 * data.len, data.value);
}

bool VarUInteger::unpack_var_uint(vm::CellSlice& cs, int& n, int& len, RefInt256& value) const {
  return (n = m_) >= 0
      && cs.fetch_uint_less(m_, len)
      && cs.fetch_uint256_to(8 * len, value);
}

bool VarUInteger::cell_unpack(Ref<vm::Cell> cell_ref, VarUInteger::Record& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool VarUInteger::cell_unpack_var_uint(Ref<vm::Cell> cell_ref, int& n, int& len, RefInt256& value) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_var_uint(cs, n, len, value) && cs.empty_ext();
}

bool VarUInteger::pack(vm::CellBuilder& cb, const VarUInteger::Record& data) const {
  return cb.store_uint_less(m_, data.len)
      && cb.store_int256_bool(data.value, 8 * data.len, false);
}

bool VarUInteger::pack_var_uint(vm::CellBuilder& cb, int len, RefInt256 value) const {
  return cb.store_uint_less(m_, len)
      && cb.store_int256_bool(value, 8 * len, false);
}

bool VarUInteger::cell_pack(Ref<vm::Cell>& cell_ref, const VarUInteger::Record& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool VarUInteger::cell_pack_var_uint(Ref<vm::Cell>& cell_ref, int len, RefInt256 value) const {
  vm::CellBuilder cb;
  return pack_var_uint(cb, len, std::move(value)) && std::move(cb).finalize_to(cell_ref);
}

bool VarUInteger::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  int len;
  return pp.open("var_uint")
      && cs.fetch_uint_less(m_, len)
      && pp.field_int(len, "len")
      && pp.fetch_uint256_field(cs, 8 * len, "value")
      && pp.close();
}


//
// code for type `MsgAddressExt`
//

int MsgAddressExt::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case addr_none:
    return cs.have(2) ? addr_none : -1;
  case addr_extern:
    return cs.prefetch_ulong(2) == 1 ? addr_extern : -1;
  }
  return -1;
}

bool MsgAddressExt::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case addr_none:
    return cs.advance(2);
  case addr_extern: {
    int len;
    return cs.advance(2)
        && cs.fetch_uint_to(9, len)
        && cs.advance(len);
    }
  }
  return false;
}

bool MsgAddressExt::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case addr_none:
    return cs.advance(2);
  case addr_extern: {
    int len;
    return cs.fetch_ulong(2) == 1
        && cs.fetch_uint_to(9, len)
        && cs.advance(len);
    }
  }
  return false;
}

bool MsgAddressExt::unpack(vm::CellSlice& cs, MsgAddressExt::Record_addr_none& data) const {
  return cs.fetch_ulong(2) == 0;
}

bool MsgAddressExt::unpack_addr_none(vm::CellSlice& cs) const {
  return cs.fetch_ulong(2) == 0;
}

bool MsgAddressExt::cell_unpack(Ref<vm::Cell> cell_ref, MsgAddressExt::Record_addr_none& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool MsgAddressExt::cell_unpack_addr_none(Ref<vm::Cell> cell_ref) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_addr_none(cs) && cs.empty_ext();
}

bool MsgAddressExt::unpack(vm::CellSlice& cs, MsgAddressExt::Record_addr_extern& data) const {
  return cs.fetch_ulong(2) == 1
      && cs.fetch_uint_to(9, data.len)
      && cs.fetch_bitstring_to(data.len, data.external_address);
}

bool MsgAddressExt::unpack_addr_extern(vm::CellSlice& cs, int& len, Ref<td::BitString>& external_address) const {
  return cs.fetch_ulong(2) == 1
      && cs.fetch_uint_to(9, len)
      && cs.fetch_bitstring_to(len, external_address);
}

bool MsgAddressExt::cell_unpack(Ref<vm::Cell> cell_ref, MsgAddressExt::Record_addr_extern& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool MsgAddressExt::cell_unpack_addr_extern(Ref<vm::Cell> cell_ref, int& len, Ref<td::BitString>& external_address) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_addr_extern(cs, len, external_address) && cs.empty_ext();
}

bool MsgAddressExt::pack(vm::CellBuilder& cb, const MsgAddressExt::Record_addr_none& data) const {
  return cb.store_long_bool(0, 2);
}

bool MsgAddressExt::pack_addr_none(vm::CellBuilder& cb) const {
  return cb.store_long_bool(0, 2);
}

bool MsgAddressExt::cell_pack(Ref<vm::Cell>& cell_ref, const MsgAddressExt::Record_addr_none& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool MsgAddressExt::cell_pack_addr_none(Ref<vm::Cell>& cell_ref) const {
  vm::CellBuilder cb;
  return pack_addr_none(cb) && std::move(cb).finalize_to(cell_ref);
}

bool MsgAddressExt::pack(vm::CellBuilder& cb, const MsgAddressExt::Record_addr_extern& data) const {
  return cb.store_long_bool(1, 2)
      && cb.store_ulong_rchk_bool(data.len, 9)
      && cb.append_bitstring_chk(data.external_address, data.len);
}

bool MsgAddressExt::pack_addr_extern(vm::CellBuilder& cb, int len, Ref<td::BitString> external_address) const {
  return cb.store_long_bool(1, 2)
      && cb.store_ulong_rchk_bool(len, 9)
      && cb.append_bitstring_chk(external_address, len);
}

bool MsgAddressExt::cell_pack(Ref<vm::Cell>& cell_ref, const MsgAddressExt::Record_addr_extern& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool MsgAddressExt::cell_pack_addr_extern(Ref<vm::Cell>& cell_ref, int len, Ref<td::BitString> external_address) const {
  vm::CellBuilder cb;
  return pack_addr_extern(cb, len, std::move(external_address)) && std::move(cb).finalize_to(cell_ref);
}

bool MsgAddressExt::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case addr_none:
    return cs.advance(2)
        && pp.cons("addr_none");
  case addr_extern: {
    int len;
    return cs.fetch_ulong(2) == 1
        && pp.open("addr_extern")
        && cs.fetch_uint_to(9, len)
        && pp.field_int(len, "len")
        && pp.fetch_bits_field(cs, len, "external_address")
        && pp.close();
    }
  }
  return pp.fail("unknown constructor for MsgAddressExt");
}

const MsgAddressExt t_MsgAddressExt;

//
// code for type `Anycast`
//

int Anycast::check_tag(const vm::CellSlice& cs) const {
  return anycast_info;
}

bool Anycast::skip(vm::CellSlice& cs) const {
  int depth;
  return cs.fetch_uint_leq(30, depth)
      && 1 <= depth
      && cs.advance(depth);
}

bool Anycast::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  int depth;
  return cs.fetch_uint_leq(30, depth)
      && 1 <= depth
      && cs.advance(depth);
}

bool Anycast::unpack(vm::CellSlice& cs, Anycast::Record& data) const {
  return cs.fetch_uint_leq(30, data.depth)
      && 1 <= data.depth
      && cs.fetch_bitstring_to(data.depth, data.rewrite_pfx);
}

bool Anycast::unpack_anycast_info(vm::CellSlice& cs, int& depth, Ref<td::BitString>& rewrite_pfx) const {
  return cs.fetch_uint_leq(30, depth)
      && 1 <= depth
      && cs.fetch_bitstring_to(depth, rewrite_pfx);
}

bool Anycast::cell_unpack(Ref<vm::Cell> cell_ref, Anycast::Record& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool Anycast::cell_unpack_anycast_info(Ref<vm::Cell> cell_ref, int& depth, Ref<td::BitString>& rewrite_pfx) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_anycast_info(cs, depth, rewrite_pfx) && cs.empty_ext();
}

bool Anycast::pack(vm::CellBuilder& cb, const Anycast::Record& data) const {
  return cb.store_uint_leq(30, data.depth)
      && 1 <= data.depth
      && cb.append_bitstring_chk(data.rewrite_pfx, data.depth);
}

bool Anycast::pack_anycast_info(vm::CellBuilder& cb, int depth, Ref<td::BitString> rewrite_pfx) const {
  return cb.store_uint_leq(30, depth)
      && 1 <= depth
      && cb.append_bitstring_chk(rewrite_pfx, depth);
}

bool Anycast::cell_pack(Ref<vm::Cell>& cell_ref, const Anycast::Record& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool Anycast::cell_pack_anycast_info(Ref<vm::Cell>& cell_ref, int depth, Ref<td::BitString> rewrite_pfx) const {
  vm::CellBuilder cb;
  return pack_anycast_info(cb, depth, std::move(rewrite_pfx)) && std::move(cb).finalize_to(cell_ref);
}

bool Anycast::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  int depth;
  return pp.open("anycast_info")
      && cs.fetch_uint_leq(30, depth)
      && pp.field_int(depth, "depth")
      && 1 <= depth
      && pp.fetch_bits_field(cs, depth, "rewrite_pfx")
      && pp.close();
}

const Anycast t_Anycast;

//
// code for type `MsgAddressInt`
//
constexpr unsigned char MsgAddressInt::cons_tag[2];

int MsgAddressInt::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case addr_std:
    return cs.have(2) ? addr_std : -1;
  case addr_var:
    return cs.have(2) ? addr_var : -1;
  }
  return -1;
}

bool MsgAddressInt::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case addr_std:
    return cs.advance(2)
        && t_Maybe_Anycast.skip(cs)
        && cs.advance(264);
  case addr_var: {
    int addr_len;
    return cs.advance(2)
        && t_Maybe_Anycast.skip(cs)
        && cs.fetch_uint_to(9, addr_len)
        && cs.advance(32)
        && cs.advance(addr_len);
    }
  }
  return false;
}

bool MsgAddressInt::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case addr_std:
    return cs.advance(2)
        && t_Maybe_Anycast.validate_skip(ops, cs, weak)
        && cs.advance(264);
  case addr_var: {
    int addr_len;
    return cs.advance(2)
        && t_Maybe_Anycast.validate_skip(ops, cs, weak)
        && cs.fetch_uint_to(9, addr_len)
        && cs.advance(32)
        && cs.advance(addr_len);
    }
  }
  return false;
}

bool MsgAddressInt::unpack(vm::CellSlice& cs, MsgAddressInt::Record_addr_std& data) const {
  return cs.fetch_ulong(2) == 2
      && t_Maybe_Anycast.fetch_to(cs, data.anycast)
      && cs.fetch_int_to(8, data.workchain_id)
      && cs.fetch_bits_to(data.address.bits(), 256);
}

bool MsgAddressInt::unpack_addr_std(vm::CellSlice& cs, Ref<CellSlice>& anycast, int& workchain_id, td::BitArray<256>& address) const {
  return cs.fetch_ulong(2) == 2
      && t_Maybe_Anycast.fetch_to(cs, anycast)
      && cs.fetch_int_to(8, workchain_id)
      && cs.fetch_bits_to(address.bits(), 256);
}

bool MsgAddressInt::cell_unpack(Ref<vm::Cell> cell_ref, MsgAddressInt::Record_addr_std& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool MsgAddressInt::cell_unpack_addr_std(Ref<vm::Cell> cell_ref, Ref<CellSlice>& anycast, int& workchain_id, td::BitArray<256>& address) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_addr_std(cs, anycast, workchain_id, address) && cs.empty_ext();
}

bool MsgAddressInt::unpack(vm::CellSlice& cs, MsgAddressInt::Record_addr_var& data) const {
  return cs.fetch_ulong(2) == 3
      && t_Maybe_Anycast.fetch_to(cs, data.anycast)
      && cs.fetch_uint_to(9, data.addr_len)
      && cs.fetch_int_to(32, data.workchain_id)
      && cs.fetch_bitstring_to(data.addr_len, data.address);
}

bool MsgAddressInt::cell_unpack(Ref<vm::Cell> cell_ref, MsgAddressInt::Record_addr_var& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool MsgAddressInt::pack(vm::CellBuilder& cb, const MsgAddressInt::Record_addr_std& data) const {
  return cb.store_long_bool(2, 2)
      && t_Maybe_Anycast.store_from(cb, data.anycast)
      && cb.store_long_rchk_bool(data.workchain_id, 8)
      && cb.store_bits_bool(data.address.cbits(), 256);
}

bool MsgAddressInt::pack_addr_std(vm::CellBuilder& cb, Ref<CellSlice> anycast, int workchain_id, td::BitArray<256> address) const {
  return cb.store_long_bool(2, 2)
      && t_Maybe_Anycast.store_from(cb, anycast)
      && cb.store_long_rchk_bool(workchain_id, 8)
      && cb.store_bits_bool(address.cbits(), 256);
}

bool MsgAddressInt::cell_pack(Ref<vm::Cell>& cell_ref, const MsgAddressInt::Record_addr_std& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool MsgAddressInt::cell_pack_addr_std(Ref<vm::Cell>& cell_ref, Ref<CellSlice> anycast, int workchain_id, td::BitArray<256> address) const {
  vm::CellBuilder cb;
  return pack_addr_std(cb, std::move(anycast), workchain_id, address) && std::move(cb).finalize_to(cell_ref);
}

bool MsgAddressInt::pack(vm::CellBuilder& cb, const MsgAddressInt::Record_addr_var& data) const {
  return cb.store_long_bool(3, 2)
      && t_Maybe_Anycast.store_from(cb, data.anycast)
      && cb.store_ulong_rchk_bool(data.addr_len, 9)
      && cb.store_long_rchk_bool(data.workchain_id, 32)
      && cb.append_bitstring_chk(data.address, data.addr_len);
}

bool MsgAddressInt::cell_pack(Ref<vm::Cell>& cell_ref, const MsgAddressInt::Record_addr_var& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool MsgAddressInt::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case addr_std:
    return cs.advance(2)
        && pp.open("addr_std")
        && pp.field("anycast")
        && t_Maybe_Anycast.print_skip(pp, cs)
        && pp.fetch_int_field(cs, 8, "workchain_id")
        && pp.fetch_bits_field(cs, 256, "address")
        && pp.close();
  case addr_var: {
    int addr_len;
    return cs.advance(2)
        && pp.open("addr_var")
        && pp.field("anycast")
        && t_Maybe_Anycast.print_skip(pp, cs)
        && cs.fetch_uint_to(9, addr_len)
        && pp.field_int(addr_len, "addr_len")
        && pp.fetch_int_field(cs, 32, "workchain_id")
        && pp.fetch_bits_field(cs, addr_len, "address")
        && pp.close();
    }
  }
  return pp.fail("unknown constructor for MsgAddressInt");
}

const MsgAddressInt t_MsgAddressInt;

//
// code for type `MsgAddress`
//

int MsgAddress::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case cons1:
    return cons1;
  case cons2:
    return cons2;
  }
  return -1;
}

bool MsgAddress::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case cons1:
    return t_MsgAddressInt.skip(cs);
  case cons2:
    return t_MsgAddressExt.skip(cs);
  }
  return false;
}

bool MsgAddress::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case cons1:
    return t_MsgAddressInt.validate_skip(ops, cs, weak);
  case cons2:
    return t_MsgAddressExt.validate_skip(ops, cs, weak);
  }
  return false;
}

bool MsgAddress::unpack(vm::CellSlice& cs, MsgAddress::Record_cons1& data) const {
  return t_MsgAddressInt.fetch_to(cs, data.x);
}

bool MsgAddress::unpack_cons1(vm::CellSlice& cs, Ref<CellSlice>& x) const {
  return t_MsgAddressInt.fetch_to(cs, x);
}

bool MsgAddress::cell_unpack(Ref<vm::Cell> cell_ref, MsgAddress::Record_cons1& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool MsgAddress::cell_unpack_cons1(Ref<vm::Cell> cell_ref, Ref<CellSlice>& x) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_cons1(cs, x) && cs.empty_ext();
}

bool MsgAddress::unpack(vm::CellSlice& cs, MsgAddress::Record_cons2& data) const {
  return t_MsgAddressExt.fetch_to(cs, data.x);
}

bool MsgAddress::unpack_cons2(vm::CellSlice& cs, Ref<CellSlice>& x) const {
  return t_MsgAddressExt.fetch_to(cs, x);
}

bool MsgAddress::cell_unpack(Ref<vm::Cell> cell_ref, MsgAddress::Record_cons2& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool MsgAddress::cell_unpack_cons2(Ref<vm::Cell> cell_ref, Ref<CellSlice>& x) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_cons2(cs, x) && cs.empty_ext();
}

bool MsgAddress::pack(vm::CellBuilder& cb, const MsgAddress::Record_cons1& data) const {
  return t_MsgAddressInt.store_from(cb, data.x);
}

bool MsgAddress::pack_cons1(vm::CellBuilder& cb, Ref<CellSlice> x) const {
  return t_MsgAddressInt.store_from(cb, x);
}

bool MsgAddress::cell_pack(Ref<vm::Cell>& cell_ref, const MsgAddress::Record_cons1& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool MsgAddress::cell_pack_cons1(Ref<vm::Cell>& cell_ref, Ref<CellSlice> x) const {
  vm::CellBuilder cb;
  return pack_cons1(cb, std::move(x)) && std::move(cb).finalize_to(cell_ref);
}

bool MsgAddress::pack(vm::CellBuilder& cb, const MsgAddress::Record_cons2& data) const {
  return t_MsgAddressExt.store_from(cb, data.x);
}

bool MsgAddress::pack_cons2(vm::CellBuilder& cb, Ref<CellSlice> x) const {
  return t_MsgAddressExt.store_from(cb, x);
}

bool MsgAddress::cell_pack(Ref<vm::Cell>& cell_ref, const MsgAddress::Record_cons2& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool MsgAddress::cell_pack_cons2(Ref<vm::Cell>& cell_ref, Ref<CellSlice> x) const {
  vm::CellBuilder cb;
  return pack_cons2(cb, std::move(x)) && std::move(cb).finalize_to(cell_ref);
}

bool MsgAddress::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case cons1:
    return pp.open()
        && pp.field()
        && t_MsgAddressInt.print_skip(pp, cs)
        && pp.close();
  case cons2:
    return pp.open()
        && pp.field()
        && t_MsgAddressExt.print_skip(pp, cs)
        && pp.close();
  }
  return pp.fail("unknown constructor for MsgAddress");
}

const MsgAddress t_MsgAddress;

//
// code for type `InternalMsgBody`
//
constexpr unsigned InternalMsgBody::cons_tag[7];

int InternalMsgBody::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case transfer_jetton:
    return cs.prefetch_ulong(32) == 0xf8a7ea5 ? transfer_jetton : -1;
  case transfer_notification:
    return cs.prefetch_ulong(32) == 0x7362d09c ? transfer_notification : -1;
  case excesses:
    return cs.prefetch_ulong(32) == 0xd53276dbU ? excesses : -1;
  case burn:
    return cs.prefetch_ulong(32) == 0x595f07bc ? burn : -1;
  case transfer_nft:
    return cs.prefetch_ulong(32) == 0x5fcc3d14 ? transfer_nft : -1;
  case internal_transfer:
    return cs.prefetch_ulong(32) == 0x978d4519U ? internal_transfer : -1;
  case burn_notification:
    return cs.prefetch_ulong(32) == 0x7bdd97de ? burn_notification : -1;
  }
  return -1;
}

bool InternalMsgBody::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case transfer_jetton:
    return cs.advance(96)
        && t_VarUInteger_16.skip(cs)
        && t_MsgAddress.skip(cs)
        && t_MsgAddress.skip(cs)
        && t_Maybe_Ref_Cell.skip(cs)
        && t_VarUInteger_16.skip(cs)
        && t_Either_Cell_Ref_Cell.skip(cs);
  case transfer_notification:
    return cs.advance(96)
        && t_VarUInteger_16.skip(cs)
        && t_MsgAddress.skip(cs)
        && t_Either_Cell_Ref_Cell.skip(cs);
  case excesses:
    return cs.advance(96);
  case burn:
    return cs.advance(96)
        && t_VarUInteger_16.skip(cs)
        && t_MsgAddress.skip(cs)
        && t_Maybe_Ref_Cell.skip(cs);
  case transfer_nft:
    return cs.advance(96)
        && t_MsgAddress.skip(cs)
        && t_MsgAddress.skip(cs)
        && t_Maybe_Ref_Cell.skip(cs)
        && t_VarUInteger_16.skip(cs)
        && t_Either_Cell_Ref_Cell.skip(cs);
  case internal_transfer:
    return cs.advance(96)
        && t_VarUInteger_16.skip(cs)
        && t_MsgAddress.skip(cs)
        && t_MsgAddress.skip(cs)
        && t_VarUInteger_16.skip(cs)
        && t_Either_Cell_Ref_Cell.skip(cs);
  case burn_notification:
    return cs.advance(96)
        && t_VarUInteger_16.skip(cs)
        && t_MsgAddress.skip(cs)
        && t_MsgAddress.skip(cs);
  }
  return false;
}

bool InternalMsgBody::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case transfer_jetton:
    return cs.fetch_ulong(32) == 0xf8a7ea5
        && cs.advance(64)
        && t_VarUInteger_16.validate_skip(ops, cs, weak)
        && t_MsgAddress.validate_skip(ops, cs, weak)
        && t_MsgAddress.validate_skip(ops, cs, weak)
        && t_Maybe_Ref_Cell.validate_skip(ops, cs, weak)
        && t_VarUInteger_16.validate_skip(ops, cs, weak)
        && t_Either_Cell_Ref_Cell.validate_skip(ops, cs, weak);
  case transfer_notification:
    return cs.fetch_ulong(32) == 0x7362d09c
        && cs.advance(64)
        && t_VarUInteger_16.validate_skip(ops, cs, weak)
        && t_MsgAddress.validate_skip(ops, cs, weak)
        && t_Either_Cell_Ref_Cell.validate_skip(ops, cs, weak);
  case excesses:
    return cs.fetch_ulong(32) == 0xd53276dbU
        && cs.advance(64);
  case burn:
    return cs.fetch_ulong(32) == 0x595f07bc
        && cs.advance(64)
        && t_VarUInteger_16.validate_skip(ops, cs, weak)
        && t_MsgAddress.validate_skip(ops, cs, weak)
        && t_Maybe_Ref_Cell.validate_skip(ops, cs, weak);
  case transfer_nft:
    return cs.fetch_ulong(32) == 0x5fcc3d14
        && cs.advance(64)
        && t_MsgAddress.validate_skip(ops, cs, weak)
        && t_MsgAddress.validate_skip(ops, cs, weak)
        && t_Maybe_Ref_Cell.validate_skip(ops, cs, weak)
        && t_VarUInteger_16.validate_skip(ops, cs, weak)
        && t_Either_Cell_Ref_Cell.validate_skip(ops, cs, weak);
  case internal_transfer:
    return cs.fetch_ulong(32) == 0x978d4519U
        && cs.advance(64)
        && t_VarUInteger_16.validate_skip(ops, cs, weak)
        && t_MsgAddress.validate_skip(ops, cs, weak)
        && t_MsgAddress.validate_skip(ops, cs, weak)
        && t_VarUInteger_16.validate_skip(ops, cs, weak)
        && t_Either_Cell_Ref_Cell.validate_skip(ops, cs, weak);
  case burn_notification:
    return cs.fetch_ulong(32) == 0x7bdd97de
        && cs.advance(64)
        && t_VarUInteger_16.validate_skip(ops, cs, weak)
        && t_MsgAddress.validate_skip(ops, cs, weak)
        && t_MsgAddress.validate_skip(ops, cs, weak);
  }
  return false;
}

bool InternalMsgBody::unpack(vm::CellSlice& cs, InternalMsgBody::Record_transfer_jetton& data) const {
  return cs.fetch_ulong(32) == 0xf8a7ea5
      && cs.fetch_uint_to(64, data.query_id)
      && t_VarUInteger_16.fetch_to(cs, data.amount)
      && t_MsgAddress.fetch_to(cs, data.destination)
      && t_MsgAddress.fetch_to(cs, data.response_destination)
      && t_Maybe_Ref_Cell.fetch_to(cs, data.custom_payload)
      && t_VarUInteger_16.fetch_to(cs, data.forward_ton_amount)
      && t_Either_Cell_Ref_Cell.fetch_to(cs, data.forward_payload);
}

bool InternalMsgBody::cell_unpack(Ref<vm::Cell> cell_ref, InternalMsgBody::Record_transfer_jetton& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool InternalMsgBody::unpack(vm::CellSlice& cs, InternalMsgBody::Record_transfer_notification& data) const {
  return cs.fetch_ulong(32) == 0x7362d09c
      && cs.fetch_uint_to(64, data.query_id)
      && t_VarUInteger_16.fetch_to(cs, data.amount)
      && t_MsgAddress.fetch_to(cs, data.sender)
      && t_Either_Cell_Ref_Cell.fetch_to(cs, data.forward_payload);
}

bool InternalMsgBody::cell_unpack(Ref<vm::Cell> cell_ref, InternalMsgBody::Record_transfer_notification& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool InternalMsgBody::unpack(vm::CellSlice& cs, InternalMsgBody::Record_excesses& data) const {
  return cs.fetch_ulong(32) == 0xd53276dbU
      && cs.fetch_uint_to(64, data.query_id);
}

bool InternalMsgBody::unpack_excesses(vm::CellSlice& cs, unsigned long long& query_id) const {
  return cs.fetch_ulong(32) == 0xd53276dbU
      && cs.fetch_uint_to(64, query_id);
}

bool InternalMsgBody::cell_unpack(Ref<vm::Cell> cell_ref, InternalMsgBody::Record_excesses& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool InternalMsgBody::cell_unpack_excesses(Ref<vm::Cell> cell_ref, unsigned long long& query_id) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_excesses(cs, query_id) && cs.empty_ext();
}

bool InternalMsgBody::unpack(vm::CellSlice& cs, InternalMsgBody::Record_burn& data) const {
  return cs.fetch_ulong(32) == 0x595f07bc
      && cs.fetch_uint_to(64, data.query_id)
      && t_VarUInteger_16.fetch_to(cs, data.amount)
      && t_MsgAddress.fetch_to(cs, data.response_destination)
      && t_Maybe_Ref_Cell.fetch_to(cs, data.custom_payload);
}

bool InternalMsgBody::cell_unpack(Ref<vm::Cell> cell_ref, InternalMsgBody::Record_burn& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool InternalMsgBody::unpack(vm::CellSlice& cs, InternalMsgBody::Record_transfer_nft& data) const {
  return cs.fetch_ulong(32) == 0x5fcc3d14
      && cs.fetch_uint_to(64, data.query_id)
      && t_MsgAddress.fetch_to(cs, data.new_owner)
      && t_MsgAddress.fetch_to(cs, data.response_destination)
      && t_Maybe_Ref_Cell.fetch_to(cs, data.custom_payload)
      && t_VarUInteger_16.fetch_to(cs, data.forward_amount)
      && t_Either_Cell_Ref_Cell.fetch_to(cs, data.forward_payload);
}

bool InternalMsgBody::cell_unpack(Ref<vm::Cell> cell_ref, InternalMsgBody::Record_transfer_nft& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool InternalMsgBody::unpack(vm::CellSlice& cs, InternalMsgBody::Record_internal_transfer& data) const {
  return cs.fetch_ulong(32) == 0x978d4519U
      && cs.fetch_uint_to(64, data.query_id)
      && t_VarUInteger_16.fetch_to(cs, data.amount)
      && t_MsgAddress.fetch_to(cs, data.from)
      && t_MsgAddress.fetch_to(cs, data.response_address)
      && t_VarUInteger_16.fetch_to(cs, data.forward_ton_amount)
      && t_Either_Cell_Ref_Cell.fetch_to(cs, data.forward_payload);
}

bool InternalMsgBody::cell_unpack(Ref<vm::Cell> cell_ref, InternalMsgBody::Record_internal_transfer& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool InternalMsgBody::unpack(vm::CellSlice& cs, InternalMsgBody::Record_burn_notification& data) const {
  return cs.fetch_ulong(32) == 0x7bdd97de
      && cs.fetch_uint_to(64, data.query_id)
      && t_VarUInteger_16.fetch_to(cs, data.amount)
      && t_MsgAddress.fetch_to(cs, data.sender)
      && t_MsgAddress.fetch_to(cs, data.response_destination);
}

bool InternalMsgBody::cell_unpack(Ref<vm::Cell> cell_ref, InternalMsgBody::Record_burn_notification& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool InternalMsgBody::pack(vm::CellBuilder& cb, const InternalMsgBody::Record_transfer_jetton& data) const {
  return cb.store_long_bool(0xf8a7ea5, 32)
      && cb.store_ulong_rchk_bool(data.query_id, 64)
      && t_VarUInteger_16.store_from(cb, data.amount)
      && t_MsgAddress.store_from(cb, data.destination)
      && t_MsgAddress.store_from(cb, data.response_destination)
      && t_Maybe_Ref_Cell.store_from(cb, data.custom_payload)
      && t_VarUInteger_16.store_from(cb, data.forward_ton_amount)
      && t_Either_Cell_Ref_Cell.store_from(cb, data.forward_payload);
}

bool InternalMsgBody::cell_pack(Ref<vm::Cell>& cell_ref, const InternalMsgBody::Record_transfer_jetton& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool InternalMsgBody::pack(vm::CellBuilder& cb, const InternalMsgBody::Record_transfer_notification& data) const {
  return cb.store_long_bool(0x7362d09c, 32)
      && cb.store_ulong_rchk_bool(data.query_id, 64)
      && t_VarUInteger_16.store_from(cb, data.amount)
      && t_MsgAddress.store_from(cb, data.sender)
      && t_Either_Cell_Ref_Cell.store_from(cb, data.forward_payload);
}

bool InternalMsgBody::cell_pack(Ref<vm::Cell>& cell_ref, const InternalMsgBody::Record_transfer_notification& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool InternalMsgBody::pack(vm::CellBuilder& cb, const InternalMsgBody::Record_excesses& data) const {
  return cb.store_long_bool(0xd53276dbU, 32)
      && cb.store_ulong_rchk_bool(data.query_id, 64);
}

bool InternalMsgBody::pack_excesses(vm::CellBuilder& cb, unsigned long long query_id) const {
  return cb.store_long_bool(0xd53276dbU, 32)
      && cb.store_ulong_rchk_bool(query_id, 64);
}

bool InternalMsgBody::cell_pack(Ref<vm::Cell>& cell_ref, const InternalMsgBody::Record_excesses& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool InternalMsgBody::cell_pack_excesses(Ref<vm::Cell>& cell_ref, unsigned long long query_id) const {
  vm::CellBuilder cb;
  return pack_excesses(cb, query_id) && std::move(cb).finalize_to(cell_ref);
}

bool InternalMsgBody::pack(vm::CellBuilder& cb, const InternalMsgBody::Record_burn& data) const {
  return cb.store_long_bool(0x595f07bc, 32)
      && cb.store_ulong_rchk_bool(data.query_id, 64)
      && t_VarUInteger_16.store_from(cb, data.amount)
      && t_MsgAddress.store_from(cb, data.response_destination)
      && t_Maybe_Ref_Cell.store_from(cb, data.custom_payload);
}

bool InternalMsgBody::cell_pack(Ref<vm::Cell>& cell_ref, const InternalMsgBody::Record_burn& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool InternalMsgBody::pack(vm::CellBuilder& cb, const InternalMsgBody::Record_transfer_nft& data) const {
  return cb.store_long_bool(0x5fcc3d14, 32)
      && cb.store_ulong_rchk_bool(data.query_id, 64)
      && t_MsgAddress.store_from(cb, data.new_owner)
      && t_MsgAddress.store_from(cb, data.response_destination)
      && t_Maybe_Ref_Cell.store_from(cb, data.custom_payload)
      && t_VarUInteger_16.store_from(cb, data.forward_amount)
      && t_Either_Cell_Ref_Cell.store_from(cb, data.forward_payload);
}

bool InternalMsgBody::cell_pack(Ref<vm::Cell>& cell_ref, const InternalMsgBody::Record_transfer_nft& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool InternalMsgBody::pack(vm::CellBuilder& cb, const InternalMsgBody::Record_internal_transfer& data) const {
  return cb.store_long_bool(0x978d4519U, 32)
      && cb.store_ulong_rchk_bool(data.query_id, 64)
      && t_VarUInteger_16.store_from(cb, data.amount)
      && t_MsgAddress.store_from(cb, data.from)
      && t_MsgAddress.store_from(cb, data.response_address)
      && t_VarUInteger_16.store_from(cb, data.forward_ton_amount)
      && t_Either_Cell_Ref_Cell.store_from(cb, data.forward_payload);
}

bool InternalMsgBody::cell_pack(Ref<vm::Cell>& cell_ref, const InternalMsgBody::Record_internal_transfer& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool InternalMsgBody::pack(vm::CellBuilder& cb, const InternalMsgBody::Record_burn_notification& data) const {
  return cb.store_long_bool(0x7bdd97de, 32)
      && cb.store_ulong_rchk_bool(data.query_id, 64)
      && t_VarUInteger_16.store_from(cb, data.amount)
      && t_MsgAddress.store_from(cb, data.sender)
      && t_MsgAddress.store_from(cb, data.response_destination);
}

bool InternalMsgBody::cell_pack(Ref<vm::Cell>& cell_ref, const InternalMsgBody::Record_burn_notification& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool InternalMsgBody::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case transfer_jetton:
    return cs.fetch_ulong(32) == 0xf8a7ea5
        && pp.open("transfer_jetton")
        && pp.fetch_uint_field(cs, 64, "query_id")
        && pp.field("amount")
        && t_VarUInteger_16.print_skip(pp, cs)
        && pp.field("destination")
        && t_MsgAddress.print_skip(pp, cs)
        && pp.field("response_destination")
        && t_MsgAddress.print_skip(pp, cs)
        && pp.field("custom_payload")
        && t_Maybe_Ref_Cell.print_skip(pp, cs)
        && pp.field("forward_ton_amount")
        && t_VarUInteger_16.print_skip(pp, cs)
        && pp.field("forward_payload")
        && t_Either_Cell_Ref_Cell.print_skip(pp, cs)
        && pp.close();
  case transfer_notification:
    return cs.fetch_ulong(32) == 0x7362d09c
        && pp.open("transfer_notification")
        && pp.fetch_uint_field(cs, 64, "query_id")
        && pp.field("amount")
        && t_VarUInteger_16.print_skip(pp, cs)
        && pp.field("sender")
        && t_MsgAddress.print_skip(pp, cs)
        && pp.field("forward_payload")
        && t_Either_Cell_Ref_Cell.print_skip(pp, cs)
        && pp.close();
  case excesses:
    return cs.fetch_ulong(32) == 0xd53276dbU
        && pp.open("excesses")
        && pp.fetch_uint_field(cs, 64, "query_id")
        && pp.close();
  case burn:
    return cs.fetch_ulong(32) == 0x595f07bc
        && pp.open("burn")
        && pp.fetch_uint_field(cs, 64, "query_id")
        && pp.field("amount")
        && t_VarUInteger_16.print_skip(pp, cs)
        && pp.field("response_destination")
        && t_MsgAddress.print_skip(pp, cs)
        && pp.field("custom_payload")
        && t_Maybe_Ref_Cell.print_skip(pp, cs)
        && pp.close();
  case transfer_nft:
    return cs.fetch_ulong(32) == 0x5fcc3d14
        && pp.open("transfer_nft")
        && pp.fetch_uint_field(cs, 64, "query_id")
        && pp.field("new_owner")
        && t_MsgAddress.print_skip(pp, cs)
        && pp.field("response_destination")
        && t_MsgAddress.print_skip(pp, cs)
        && pp.field("custom_payload")
        && t_Maybe_Ref_Cell.print_skip(pp, cs)
        && pp.field("forward_amount")
        && t_VarUInteger_16.print_skip(pp, cs)
        && pp.field("forward_payload")
        && t_Either_Cell_Ref_Cell.print_skip(pp, cs)
        && pp.close();
  case internal_transfer:
    return cs.fetch_ulong(32) == 0x978d4519U
        && pp.open("internal_transfer")
        && pp.fetch_uint_field(cs, 64, "query_id")
        && pp.field("amount")
        && t_VarUInteger_16.print_skip(pp, cs)
        && pp.field("from")
        && t_MsgAddress.print_skip(pp, cs)
        && pp.field("response_address")
        && t_MsgAddress.print_skip(pp, cs)
        && pp.field("forward_ton_amount")
        && t_VarUInteger_16.print_skip(pp, cs)
        && pp.field("forward_payload")
        && t_Either_Cell_Ref_Cell.print_skip(pp, cs)
        && pp.close();
  case burn_notification:
    return cs.fetch_ulong(32) == 0x7bdd97de
        && pp.open("burn_notification")
        && pp.fetch_uint_field(cs, 64, "query_id")
        && pp.field("amount")
        && t_VarUInteger_16.print_skip(pp, cs)
        && pp.field("sender")
        && t_MsgAddress.print_skip(pp, cs)
        && pp.field("response_destination")
        && t_MsgAddress.print_skip(pp, cs)
        && pp.close();
  }
  return pp.fail("unknown constructor for InternalMsgBody");
}

const InternalMsgBody t_InternalMsgBody;

//
// code for type `Bit`
//

int Bit::check_tag(const vm::CellSlice& cs) const {
  return bit;
}

bool Bit::unpack(vm::CellSlice& cs, Bit::Record& data) const {
  return cs.fetch_bool_to(data.x);
}

bool Bit::unpack_bit(vm::CellSlice& cs, bool& x) const {
  return cs.fetch_bool_to(x);
}

bool Bit::cell_unpack(Ref<vm::Cell> cell_ref, Bit::Record& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool Bit::cell_unpack_bit(Ref<vm::Cell> cell_ref, bool& x) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_bit(cs, x) && cs.empty_ext();
}

bool Bit::pack(vm::CellBuilder& cb, const Bit::Record& data) const {
  return cb.store_ulong_rchk_bool(data.x, 1);
}

bool Bit::pack_bit(vm::CellBuilder& cb, bool x) const {
  return cb.store_ulong_rchk_bool(x, 1);
}

bool Bit::cell_pack(Ref<vm::Cell>& cell_ref, const Bit::Record& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool Bit::cell_pack_bit(Ref<vm::Cell>& cell_ref, bool x) const {
  vm::CellBuilder cb;
  return pack_bit(cb, x) && std::move(cb).finalize_to(cell_ref);
}

bool Bit::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  int t1;
  return pp.open("bit")
      && cs.fetch_bool_to(t1)
      && pp.field_int(t1)
      && pp.close();
}

const Bit t_Bit;

//
// code for type `Hashmap`
//

int Hashmap::check_tag(const vm::CellSlice& cs) const {
  return hm_edge;
}

bool Hashmap::skip(vm::CellSlice& cs) const {
  int l, m;
  return HmLabel{m_}.skip(cs, l)
      && add_r1(m, l, m_)
      && HashmapNode{m, X_}.skip(cs);
}

bool Hashmap::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  int l, m;
  return HmLabel{m_}.validate_skip(ops, cs, weak, l)
      && add_r1(m, l, m_)
      && HashmapNode{m, X_}.validate_skip(ops, cs, weak);
}

bool Hashmap::unpack(vm::CellSlice& cs, Hashmap::Record& data) const {
  return (data.n = m_) >= 0
      && HmLabel{m_}.fetch_to(cs, data.label, data.l)
      && add_r1(data.m, data.l, m_)
      && HashmapNode{data.m, X_}.fetch_to(cs, data.node);
}

bool Hashmap::cell_unpack(Ref<vm::Cell> cell_ref, Hashmap::Record& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool Hashmap::pack(vm::CellBuilder& cb, const Hashmap::Record& data) const {
  int l, m;
  return tlb::store_from(cb, HmLabel{m_}, data.label, l)
      && add_r1(m, l, m_)
      && HashmapNode{m, X_}.store_from(cb, data.node);
}

bool Hashmap::cell_pack(Ref<vm::Cell>& cell_ref, const Hashmap::Record& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool Hashmap::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  int l, m;
  return pp.open("hm_edge")
      && pp.field("label")
      && HmLabel{m_}.print_skip(pp, cs, l)
      && add_r1(m, l, m_)
      && pp.field("node")
      && HashmapNode{m, X_}.print_skip(pp, cs)
      && pp.close();
}


//
// code for type `HashmapNode`
//

int HashmapNode::get_tag(const vm::CellSlice& cs) const {
  // distinguish by parameter `m_` using 1 2 2 2
  return m_ ? hmn_fork : hmn_leaf;
}

int HashmapNode::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case hmn_leaf:
    return hmn_leaf;
  case hmn_fork:
    return hmn_fork;
  }
  return -1;
}

bool HashmapNode::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case hmn_leaf:
    return m_ == 0
        && X_.skip(cs);
  case hmn_fork: {
    int n;
    return add_r1(n, 1, m_)
        && cs.advance_refs(2);
    }
  }
  return false;
}

bool HashmapNode::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case hmn_leaf:
    return m_ == 0
        && X_.validate_skip(ops, cs, weak);
  case hmn_fork: {
    int n;
    return add_r1(n, 1, m_)
        && Hashmap{n, X_}.validate_skip_ref(ops, cs, weak)
        && Hashmap{n, X_}.validate_skip_ref(ops, cs, weak);
    }
  }
  return false;
}

bool HashmapNode::unpack(vm::CellSlice& cs, HashmapNode::Record_hmn_leaf& data) const {
  return m_ == 0
      && X_.fetch_to(cs, data.value);
}

bool HashmapNode::unpack_hmn_leaf(vm::CellSlice& cs, Ref<CellSlice>& value) const {
  return m_ == 0
      && X_.fetch_to(cs, value);
}

bool HashmapNode::cell_unpack(Ref<vm::Cell> cell_ref, HashmapNode::Record_hmn_leaf& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool HashmapNode::cell_unpack_hmn_leaf(Ref<vm::Cell> cell_ref, Ref<CellSlice>& value) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_hmn_leaf(cs, value) && cs.empty_ext();
}

bool HashmapNode::unpack(vm::CellSlice& cs, HashmapNode::Record_hmn_fork& data) const {
  return add_r1(data.n, 1, m_)
      && cs.fetch_ref_to(data.left)
      && cs.fetch_ref_to(data.right);
}

bool HashmapNode::unpack_hmn_fork(vm::CellSlice& cs, int& n, Ref<Cell>& left, Ref<Cell>& right) const {
  return add_r1(n, 1, m_)
      && cs.fetch_ref_to(left)
      && cs.fetch_ref_to(right);
}

bool HashmapNode::cell_unpack(Ref<vm::Cell> cell_ref, HashmapNode::Record_hmn_fork& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool HashmapNode::cell_unpack_hmn_fork(Ref<vm::Cell> cell_ref, int& n, Ref<Cell>& left, Ref<Cell>& right) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_hmn_fork(cs, n, left, right) && cs.empty_ext();
}

bool HashmapNode::pack(vm::CellBuilder& cb, const HashmapNode::Record_hmn_leaf& data) const {
  return m_ == 0
      && X_.store_from(cb, data.value);
}

bool HashmapNode::pack_hmn_leaf(vm::CellBuilder& cb, Ref<CellSlice> value) const {
  return m_ == 0
      && X_.store_from(cb, value);
}

bool HashmapNode::cell_pack(Ref<vm::Cell>& cell_ref, const HashmapNode::Record_hmn_leaf& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool HashmapNode::cell_pack_hmn_leaf(Ref<vm::Cell>& cell_ref, Ref<CellSlice> value) const {
  vm::CellBuilder cb;
  return pack_hmn_leaf(cb, std::move(value)) && std::move(cb).finalize_to(cell_ref);
}

bool HashmapNode::pack(vm::CellBuilder& cb, const HashmapNode::Record_hmn_fork& data) const {
  int n;
  return add_r1(n, 1, m_)
      && cb.store_ref_bool(data.left)
      && cb.store_ref_bool(data.right);
}

bool HashmapNode::pack_hmn_fork(vm::CellBuilder& cb, Ref<Cell> left, Ref<Cell> right) const {
  int n;
  return add_r1(n, 1, m_)
      && cb.store_ref_bool(left)
      && cb.store_ref_bool(right);
}

bool HashmapNode::cell_pack(Ref<vm::Cell>& cell_ref, const HashmapNode::Record_hmn_fork& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool HashmapNode::cell_pack_hmn_fork(Ref<vm::Cell>& cell_ref, Ref<Cell> left, Ref<Cell> right) const {
  vm::CellBuilder cb;
  return pack_hmn_fork(cb, std::move(left), std::move(right)) && std::move(cb).finalize_to(cell_ref);
}

bool HashmapNode::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case hmn_leaf:
    return pp.open("hmn_leaf")
        && m_ == 0
        && pp.field("value")
        && X_.print_skip(pp, cs)
        && pp.close();
  case hmn_fork: {
    int n;
    return pp.open("hmn_fork")
        && add_r1(n, 1, m_)
        && pp.field("left")
        && Hashmap{n, X_}.print_ref(pp, cs.fetch_ref())
        && pp.field("right")
        && Hashmap{n, X_}.print_ref(pp, cs.fetch_ref())
        && pp.close();
    }
  }
  return pp.fail("unknown constructor for HashmapNode");
}


//
// code for type `HmLabel`
//
constexpr char HmLabel::cons_len[3];
constexpr unsigned char HmLabel::cons_tag[3];

int HmLabel::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case hml_short:
    return cs.have(1) ? hml_short : -1;
  case hml_long:
    return cs.have(2) ? hml_long : -1;
  case hml_same:
    return cs.have(2) ? hml_same : -1;
  }
  return -1;
}

bool HmLabel::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case hml_short: {
    int m_;
    return cs.advance(1)
        && t_Unary.skip(cs, m_)
        && m_ <= n_
        && cs.advance(m_);
    }
  case hml_long: {
    int m_;
    return cs.advance(2)
        && cs.fetch_uint_leq(n_, m_)
        && cs.advance(m_);
    }
  case hml_same: {
    int m_;
    return cs.advance(3)
        && cs.fetch_uint_leq(n_, m_);
    }
  }
  return false;
}

bool HmLabel::skip(vm::CellSlice& cs, int& m_) const {
  switch (get_tag(cs)) {
  case hml_short:
    return cs.advance(1)
        && t_Unary.skip(cs, m_)
        && m_ <= n_
        && cs.advance(m_);
  case hml_long:
    return cs.advance(2)
        && cs.fetch_uint_leq(n_, m_)
        && cs.advance(m_);
  case hml_same:
    return cs.advance(3)
        && cs.fetch_uint_leq(n_, m_);
  }
  return false;
}

bool HmLabel::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case hml_short: {
    int m_;
    return cs.advance(1)
        && t_Unary.validate_skip(ops, cs, weak, m_)
        && m_ <= n_
        && cs.advance(m_);
    }
  case hml_long: {
    int m_;
    return cs.advance(2)
        && cs.fetch_uint_leq(n_, m_)
        && cs.advance(m_);
    }
  case hml_same: {
    int m_;
    return cs.advance(3)
        && cs.fetch_uint_leq(n_, m_);
    }
  }
  return false;
}

bool HmLabel::validate_skip(int* ops, vm::CellSlice& cs, bool weak, int& m_) const {
  switch (get_tag(cs)) {
  case hml_short:
    return cs.advance(1)
        && t_Unary.validate_skip(ops, cs, weak, m_)
        && m_ <= n_
        && cs.advance(m_);
  case hml_long:
    return cs.advance(2)
        && cs.fetch_uint_leq(n_, m_)
        && cs.advance(m_);
  case hml_same:
    return cs.advance(3)
        && cs.fetch_uint_leq(n_, m_);
  }
  return false;
}

bool HmLabel::fetch_to(vm::CellSlice& cs, Ref<vm::CellSlice>& res, int& m_) const {
  res = Ref<vm::CellSlice>{true, cs};
  return skip(cs, m_) && res.unique_write().cut_tail(cs);
}

bool HmLabel::unpack(vm::CellSlice& cs, HmLabel::Record_hml_short& data, int& m_) const {
  return cs.fetch_ulong(1) == 0
      && (data.m = n_) >= 0
      && t_Unary.fetch_to(cs, data.len, data.n)
      && data.n <= n_
      && cs.fetch_bitstring_to(data.n, data.s)
      && (m_ = data.n) >= 0;
}

bool HmLabel::cell_unpack(Ref<vm::Cell> cell_ref, HmLabel::Record_hml_short& data, int& m_) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data, m_) && cs.empty_ext();
}

bool HmLabel::unpack(vm::CellSlice& cs, HmLabel::Record_hml_long& data, int& m_) const {
  return cs.fetch_ulong(2) == 2
      && (data.m = n_) >= 0
      && cs.fetch_uint_leq(n_, data.n)
      && cs.fetch_bitstring_to(data.n, data.s)
      && (m_ = data.n) >= 0;
}

bool HmLabel::unpack_hml_long(vm::CellSlice& cs, int& m, int& n, Ref<td::BitString>& s, int& m_) const {
  return cs.fetch_ulong(2) == 2
      && (m = n_) >= 0
      && cs.fetch_uint_leq(n_, n)
      && cs.fetch_bitstring_to(n, s)
      && (m_ = n) >= 0;
}

bool HmLabel::cell_unpack(Ref<vm::Cell> cell_ref, HmLabel::Record_hml_long& data, int& m_) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data, m_) && cs.empty_ext();
}

bool HmLabel::cell_unpack_hml_long(Ref<vm::Cell> cell_ref, int& m, int& n, Ref<td::BitString>& s, int& m_) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_hml_long(cs, m, n, s, m_) && cs.empty_ext();
}

bool HmLabel::unpack(vm::CellSlice& cs, HmLabel::Record_hml_same& data, int& m_) const {
  return cs.fetch_ulong(2) == 3
      && (data.m = n_) >= 0
      && cs.fetch_bool_to(data.v)
      && cs.fetch_uint_leq(n_, data.n)
      && (m_ = data.n) >= 0;
}

bool HmLabel::unpack_hml_same(vm::CellSlice& cs, int& m, bool& v, int& n, int& m_) const {
  return cs.fetch_ulong(2) == 3
      && (m = n_) >= 0
      && cs.fetch_bool_to(v)
      && cs.fetch_uint_leq(n_, n)
      && (m_ = n) >= 0;
}

bool HmLabel::cell_unpack(Ref<vm::Cell> cell_ref, HmLabel::Record_hml_same& data, int& m_) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data, m_) && cs.empty_ext();
}

bool HmLabel::cell_unpack_hml_same(Ref<vm::Cell> cell_ref, int& m, bool& v, int& n, int& m_) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_hml_same(cs, m, v, n, m_) && cs.empty_ext();
}

bool HmLabel::pack(vm::CellBuilder& cb, const HmLabel::Record_hml_short& data, int& m_) const {
  return cb.store_long_bool(0, 1)
      && tlb::store_from(cb, t_Unary, data.len, m_)
      && m_ <= n_
      && cb.append_bitstring_chk(data.s, m_);
}

bool HmLabel::cell_pack(Ref<vm::Cell>& cell_ref, const HmLabel::Record_hml_short& data, int& m_) const {
  vm::CellBuilder cb;
  return pack(cb, data, m_) && std::move(cb).finalize_to(cell_ref);
}

bool HmLabel::pack(vm::CellBuilder& cb, const HmLabel::Record_hml_long& data, int& m_) const {
  return cb.store_long_bool(2, 2)
      && cb.store_uint_leq(n_, data.n)
      && cb.append_bitstring_chk(data.s, data.n)
      && (m_ = data.n) >= 0;
}

bool HmLabel::pack_hml_long(vm::CellBuilder& cb, int n, Ref<td::BitString> s, int& m_) const {
  return cb.store_long_bool(2, 2)
      && cb.store_uint_leq(n_, n)
      && cb.append_bitstring_chk(s, n)
      && (m_ = n) >= 0;
}

bool HmLabel::cell_pack(Ref<vm::Cell>& cell_ref, const HmLabel::Record_hml_long& data, int& m_) const {
  vm::CellBuilder cb;
  return pack(cb, data, m_) && std::move(cb).finalize_to(cell_ref);
}

bool HmLabel::cell_pack_hml_long(Ref<vm::Cell>& cell_ref, int n, Ref<td::BitString> s, int& m_) const {
  vm::CellBuilder cb;
  return pack_hml_long(cb, n, std::move(s), m_) && std::move(cb).finalize_to(cell_ref);
}

bool HmLabel::pack(vm::CellBuilder& cb, const HmLabel::Record_hml_same& data, int& m_) const {
  return cb.store_long_bool(3, 2)
      && cb.store_ulong_rchk_bool(data.v, 1)
      && cb.store_uint_leq(n_, data.n)
      && (m_ = data.n) >= 0;
}

bool HmLabel::pack_hml_same(vm::CellBuilder& cb, bool v, int n, int& m_) const {
  return cb.store_long_bool(3, 2)
      && cb.store_ulong_rchk_bool(v, 1)
      && cb.store_uint_leq(n_, n)
      && (m_ = n) >= 0;
}

bool HmLabel::cell_pack(Ref<vm::Cell>& cell_ref, const HmLabel::Record_hml_same& data, int& m_) const {
  vm::CellBuilder cb;
  return pack(cb, data, m_) && std::move(cb).finalize_to(cell_ref);
}

bool HmLabel::cell_pack_hml_same(Ref<vm::Cell>& cell_ref, bool v, int n, int& m_) const {
  vm::CellBuilder cb;
  return pack_hml_same(cb, v, n, m_) && std::move(cb).finalize_to(cell_ref);
}

bool HmLabel::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case hml_short: {
    int m_;
    return cs.advance(1)
        && pp.open("hml_short")
        && pp.field("len")
        && t_Unary.print_skip(pp, cs, m_)
        && m_ <= n_
        && pp.fetch_bits_field(cs, m_, "s")
        && pp.close();
    }
  case hml_long: {
    int m_;
    return cs.advance(2)
        && pp.open("hml_long")
        && cs.fetch_uint_leq(n_, m_)
        && pp.field_int(m_, "n")
        && pp.fetch_bits_field(cs, m_, "s")
        && pp.close();
    }
  case hml_same: {
    int m_;
    return cs.advance(2)
        && pp.open("hml_same")
        && pp.fetch_uint_field(cs, 1, "v")
        && cs.fetch_uint_leq(n_, m_)
        && pp.field_int(m_, "n")
        && pp.close();
    }
  }
  return pp.fail("unknown constructor for HmLabel");
}

bool HmLabel::print_skip(PrettyPrinter& pp, vm::CellSlice& cs, int& m_) const {
  switch (get_tag(cs)) {
  case hml_short:
    return cs.advance(1)
        && pp.open("hml_short")
        && pp.field("len")
        && t_Unary.print_skip(pp, cs, m_)
        && m_ <= n_
        && pp.fetch_bits_field(cs, m_, "s")
        && pp.close();
  case hml_long:
    return cs.advance(2)
        && pp.open("hml_long")
        && cs.fetch_uint_leq(n_, m_)
        && pp.field_int(m_, "n")
        && pp.fetch_bits_field(cs, m_, "s")
        && pp.close();
  case hml_same:
    return cs.advance(2)
        && pp.open("hml_same")
        && pp.fetch_uint_field(cs, 1, "v")
        && cs.fetch_uint_leq(n_, m_)
        && pp.field_int(m_, "n")
        && pp.close();
  }
  return pp.fail("unknown constructor for HmLabel");
}


//
// code for type `Unary`
//

int Unary::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case unary_zero:
    return cs.have(1) ? unary_zero : -1;
  case unary_succ:
    return cs.have(1) ? unary_succ : -1;
  }
  return -1;
}

bool Unary::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case unary_zero:
    return cs.advance(1);
  case unary_succ: {
    int n;
    return cs.advance(1)
        && skip(cs, n);
    }
  }
  return false;
}

bool Unary::skip(vm::CellSlice& cs, int& m_) const {
  switch (get_tag(cs)) {
  case unary_zero:
    return (m_ = 0) >= 0
        && cs.advance(1);
  case unary_succ: {
    int n;
    return cs.advance(1)
        && skip(cs, n)
        && (m_ = n + 1) >= 0;
    }
  }
  return false;
}

bool Unary::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case unary_zero:
    return cs.advance(1);
  case unary_succ: {
    int n;
    return cs.advance(1)
        && validate_skip(ops, cs, weak, n);
    }
  }
  return false;
}

bool Unary::validate_skip(int* ops, vm::CellSlice& cs, bool weak, int& m_) const {
  switch (get_tag(cs)) {
  case unary_zero:
    return (m_ = 0) >= 0
        && cs.advance(1);
  case unary_succ: {
    int n;
    return cs.advance(1)
        && validate_skip(ops, cs, weak, n)
        && (m_ = n + 1) >= 0;
    }
  }
  return false;
}

bool Unary::fetch_to(vm::CellSlice& cs, Ref<vm::CellSlice>& res, int& m_) const {
  res = Ref<vm::CellSlice>{true, cs};
  return skip(cs, m_) && res.unique_write().cut_tail(cs);
}

bool Unary::unpack(vm::CellSlice& cs, Unary::Record_unary_zero& data, int& m_) const {
  return cs.fetch_ulong(1) == 0
      && (m_ = 0) >= 0;
}

bool Unary::unpack_unary_zero(vm::CellSlice& cs, int& m_) const {
  return cs.fetch_ulong(1) == 0
      && (m_ = 0) >= 0;
}

bool Unary::cell_unpack(Ref<vm::Cell> cell_ref, Unary::Record_unary_zero& data, int& m_) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data, m_) && cs.empty_ext();
}

bool Unary::cell_unpack_unary_zero(Ref<vm::Cell> cell_ref, int& m_) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_unary_zero(cs, m_) && cs.empty_ext();
}

bool Unary::unpack(vm::CellSlice& cs, Unary::Record_unary_succ& data, int& m_) const {
  return cs.fetch_ulong(1) == 1
      && fetch_to(cs, data.x, data.n)
      && (m_ = data.n + 1) >= 0;
}

bool Unary::unpack_unary_succ(vm::CellSlice& cs, int& n, Ref<CellSlice>& x, int& m_) const {
  return cs.fetch_ulong(1) == 1
      && fetch_to(cs, x, n)
      && (m_ = n + 1) >= 0;
}

bool Unary::cell_unpack(Ref<vm::Cell> cell_ref, Unary::Record_unary_succ& data, int& m_) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data, m_) && cs.empty_ext();
}

bool Unary::cell_unpack_unary_succ(Ref<vm::Cell> cell_ref, int& n, Ref<CellSlice>& x, int& m_) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_unary_succ(cs, n, x, m_) && cs.empty_ext();
}

bool Unary::pack(vm::CellBuilder& cb, const Unary::Record_unary_zero& data, int& m_) const {
  return cb.store_long_bool(0, 1)
      && (m_ = 0) >= 0;
}

bool Unary::pack_unary_zero(vm::CellBuilder& cb, int& m_) const {
  return cb.store_long_bool(0, 1)
      && (m_ = 0) >= 0;
}

bool Unary::cell_pack(Ref<vm::Cell>& cell_ref, const Unary::Record_unary_zero& data, int& m_) const {
  vm::CellBuilder cb;
  return pack(cb, data, m_) && std::move(cb).finalize_to(cell_ref);
}

bool Unary::cell_pack_unary_zero(Ref<vm::Cell>& cell_ref, int& m_) const {
  vm::CellBuilder cb;
  return pack_unary_zero(cb, m_) && std::move(cb).finalize_to(cell_ref);
}

bool Unary::pack(vm::CellBuilder& cb, const Unary::Record_unary_succ& data, int& m_) const {
  int n;
  return cb.store_long_bool(1, 1)
      && tlb::store_from(cb, *this, data.x, n)
      && (m_ = n + 1) >= 0;
}

bool Unary::pack_unary_succ(vm::CellBuilder& cb, Ref<CellSlice> x, int& m_) const {
  int n;
  return cb.store_long_bool(1, 1)
      && tlb::store_from(cb, *this, x, n)
      && (m_ = n + 1) >= 0;
}

bool Unary::cell_pack(Ref<vm::Cell>& cell_ref, const Unary::Record_unary_succ& data, int& m_) const {
  vm::CellBuilder cb;
  return pack(cb, data, m_) && std::move(cb).finalize_to(cell_ref);
}

bool Unary::cell_pack_unary_succ(Ref<vm::Cell>& cell_ref, Ref<CellSlice> x, int& m_) const {
  vm::CellBuilder cb;
  return pack_unary_succ(cb, std::move(x), m_) && std::move(cb).finalize_to(cell_ref);
}

bool Unary::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case unary_zero:
    return cs.advance(1)
        && pp.cons("unary_zero");
  case unary_succ: {
    int n;
    return cs.advance(1)
        && pp.open("unary_succ")
        && pp.field("x")
        && print_skip(pp, cs, n)
        && pp.close();
    }
  }
  return pp.fail("unknown constructor for Unary");
}

bool Unary::print_skip(PrettyPrinter& pp, vm::CellSlice& cs, int& m_) const {
  switch (get_tag(cs)) {
  case unary_zero:
    return cs.advance(1)
        && pp.cons("unary_zero")
        && (m_ = 0) >= 0;
  case unary_succ: {
    int n;
    return cs.advance(1)
        && pp.open("unary_succ")
        && pp.field("x")
        && print_skip(pp, cs, n)
        && (m_ = n + 1) >= 0
        && pp.close();
    }
  }
  return pp.fail("unknown constructor for Unary");
}

const Unary t_Unary;

//
// code for type `HashmapE`
//

int HashmapE::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case hme_empty:
    return cs.have(1) ? hme_empty : -1;
  case hme_root:
    return cs.have(1) ? hme_root : -1;
  }
  return -1;
}

bool HashmapE::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case hme_empty:
    return cs.advance(1);
  case hme_root:
    return cs.advance_ext(0x10001);
  }
  return false;
}

bool HashmapE::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case hme_empty:
    return cs.advance(1);
  case hme_root:
    return cs.advance(1)
        && Hashmap{m_, X_}.validate_skip_ref(ops, cs, weak);
  }
  return false;
}

bool HashmapE::unpack(vm::CellSlice& cs, HashmapE::Record_hme_empty& data) const {
  return cs.fetch_ulong(1) == 0;
}

bool HashmapE::unpack_hme_empty(vm::CellSlice& cs) const {
  return cs.fetch_ulong(1) == 0;
}

bool HashmapE::cell_unpack(Ref<vm::Cell> cell_ref, HashmapE::Record_hme_empty& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool HashmapE::cell_unpack_hme_empty(Ref<vm::Cell> cell_ref) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_hme_empty(cs) && cs.empty_ext();
}

bool HashmapE::unpack(vm::CellSlice& cs, HashmapE::Record_hme_root& data) const {
  return cs.fetch_ulong(1) == 1
      && (data.n = m_) >= 0
      && cs.fetch_ref_to(data.root);
}

bool HashmapE::unpack_hme_root(vm::CellSlice& cs, int& n, Ref<Cell>& root) const {
  return cs.fetch_ulong(1) == 1
      && (n = m_) >= 0
      && cs.fetch_ref_to(root);
}

bool HashmapE::cell_unpack(Ref<vm::Cell> cell_ref, HashmapE::Record_hme_root& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool HashmapE::cell_unpack_hme_root(Ref<vm::Cell> cell_ref, int& n, Ref<Cell>& root) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_hme_root(cs, n, root) && cs.empty_ext();
}

bool HashmapE::pack(vm::CellBuilder& cb, const HashmapE::Record_hme_empty& data) const {
  return cb.store_long_bool(0, 1);
}

bool HashmapE::pack_hme_empty(vm::CellBuilder& cb) const {
  return cb.store_long_bool(0, 1);
}

bool HashmapE::cell_pack(Ref<vm::Cell>& cell_ref, const HashmapE::Record_hme_empty& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool HashmapE::cell_pack_hme_empty(Ref<vm::Cell>& cell_ref) const {
  vm::CellBuilder cb;
  return pack_hme_empty(cb) && std::move(cb).finalize_to(cell_ref);
}

bool HashmapE::pack(vm::CellBuilder& cb, const HashmapE::Record_hme_root& data) const {
  return cb.store_long_bool(1, 1)
      && cb.store_ref_bool(data.root);
}

bool HashmapE::pack_hme_root(vm::CellBuilder& cb, Ref<Cell> root) const {
  return cb.store_long_bool(1, 1)
      && cb.store_ref_bool(root);
}

bool HashmapE::cell_pack(Ref<vm::Cell>& cell_ref, const HashmapE::Record_hme_root& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool HashmapE::cell_pack_hme_root(Ref<vm::Cell>& cell_ref, Ref<Cell> root) const {
  vm::CellBuilder cb;
  return pack_hme_root(cb, std::move(root)) && std::move(cb).finalize_to(cell_ref);
}

bool HashmapE::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case hme_empty:
    return cs.advance(1)
        && pp.cons("hme_empty");
  case hme_root:
    return cs.advance(1)
        && pp.open("hme_root")
        && pp.field("root")
        && Hashmap{m_, X_}.print_ref(pp, cs.fetch_ref())
        && pp.close();
  }
  return pp.fail("unknown constructor for HashmapE");
}


//
// code for type `ChunkedData`
//

int ChunkedData::check_tag(const vm::CellSlice& cs) const {
  return chunked_data;
}

bool ChunkedData::skip(vm::CellSlice& cs) const {
  return t_HashmapE_32_Ref_Cell.skip(cs);
}

bool ChunkedData::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  return t_HashmapE_32_Ref_Cell.validate_skip(ops, cs, weak);
}

bool ChunkedData::unpack(vm::CellSlice& cs, ChunkedData::Record& data) const {
  return t_HashmapE_32_Ref_Cell.fetch_to(cs, data.data);
}

bool ChunkedData::unpack_chunked_data(vm::CellSlice& cs, Ref<CellSlice>& data) const {
  return t_HashmapE_32_Ref_Cell.fetch_to(cs, data);
}

bool ChunkedData::cell_unpack(Ref<vm::Cell> cell_ref, ChunkedData::Record& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool ChunkedData::cell_unpack_chunked_data(Ref<vm::Cell> cell_ref, Ref<CellSlice>& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_chunked_data(cs, data) && cs.empty_ext();
}

bool ChunkedData::pack(vm::CellBuilder& cb, const ChunkedData::Record& data) const {
  return t_HashmapE_32_Ref_Cell.store_from(cb, data.data);
}

bool ChunkedData::pack_chunked_data(vm::CellBuilder& cb, Ref<CellSlice> data) const {
  return t_HashmapE_32_Ref_Cell.store_from(cb, data);
}

bool ChunkedData::cell_pack(Ref<vm::Cell>& cell_ref, const ChunkedData::Record& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool ChunkedData::cell_pack_chunked_data(Ref<vm::Cell>& cell_ref, Ref<CellSlice> data) const {
  vm::CellBuilder cb;
  return pack_chunked_data(cb, std::move(data)) && std::move(cb).finalize_to(cell_ref);
}

bool ChunkedData::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  return pp.open("chunked_data")
      && pp.field("data")
      && t_HashmapE_32_Ref_Cell.print_skip(pp, cs)
      && pp.close();
}

const ChunkedData t_ChunkedData;

//
// code for type `Text`
//

int Text::check_tag(const vm::CellSlice& cs) const {
  return text;
}

bool Text::skip(vm::CellSlice& cs) const {
  return t_Anything.skip(cs);
}

bool Text::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  return t_Anything.validate_skip(ops, cs, weak);
}

bool Text::unpack(vm::CellSlice& cs, Text::Record& data) const {
  return t_Anything.fetch_to(cs, data.data);
}

bool Text::unpack_text(vm::CellSlice& cs, Ref<CellSlice>& data) const {
  return t_Anything.fetch_to(cs, data);
}

bool Text::cell_unpack(Ref<vm::Cell> cell_ref, Text::Record& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool Text::cell_unpack_text(Ref<vm::Cell> cell_ref, Ref<CellSlice>& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_text(cs, data) && cs.empty_ext();
}

bool Text::pack(vm::CellBuilder& cb, const Text::Record& data) const {
  return t_Anything.store_from(cb, data.data);
}

bool Text::pack_text(vm::CellBuilder& cb, Ref<CellSlice> data) const {
  return t_Anything.store_from(cb, data);
}

bool Text::cell_pack(Ref<vm::Cell>& cell_ref, const Text::Record& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool Text::cell_pack_text(Ref<vm::Cell>& cell_ref, Ref<CellSlice> data) const {
  vm::CellBuilder cb;
  return pack_text(cb, std::move(data)) && std::move(cb).finalize_to(cell_ref);
}

bool Text::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  return pp.open("text")
      && pp.field("data")
      && t_Anything.print_skip(pp, cs)
      && pp.close();
}

const Text t_Text;

//
// code for type `ContentData`
//

int ContentData::get_tag(const vm::CellSlice& cs) const {
  switch (cs.bselect(6, 3)) {
  case 0:
    return cs.bit_at(7) ? chunks : snake;
  default:
    return -1;
  }
}

int ContentData::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case snake:
    return cs.prefetch_ulong(8) == 0 ? snake : -1;
  case chunks:
    return cs.prefetch_ulong(8) == 1 ? chunks : -1;
  }
  return -1;
}

bool ContentData::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case snake:
    return cs.advance(8)
        && t_Anything.skip(cs);
  case chunks:
    return cs.advance(8)
        && t_ChunkedData.skip(cs);
  }
  return false;
}

bool ContentData::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case snake:
    return cs.fetch_ulong(8) == 0
        && t_Anything.validate_skip(ops, cs, weak);
  case chunks:
    return cs.fetch_ulong(8) == 1
        && t_ChunkedData.validate_skip(ops, cs, weak);
  }
  return false;
}

bool ContentData::unpack(vm::CellSlice& cs, ContentData::Record_snake& data) const {
  return cs.fetch_ulong(8) == 0
      && t_Anything.fetch_to(cs, data.data);
}

bool ContentData::unpack_snake(vm::CellSlice& cs, Ref<CellSlice>& data) const {
  return cs.fetch_ulong(8) == 0
      && t_Anything.fetch_to(cs, data);
}

bool ContentData::cell_unpack(Ref<vm::Cell> cell_ref, ContentData::Record_snake& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool ContentData::cell_unpack_snake(Ref<vm::Cell> cell_ref, Ref<CellSlice>& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_snake(cs, data) && cs.empty_ext();
}

bool ContentData::unpack(vm::CellSlice& cs, ContentData::Record_chunks& data) const {
  return cs.fetch_ulong(8) == 1
      && t_ChunkedData.fetch_to(cs, data.data);
}

bool ContentData::unpack_chunks(vm::CellSlice& cs, Ref<CellSlice>& data) const {
  return cs.fetch_ulong(8) == 1
      && t_ChunkedData.fetch_to(cs, data);
}

bool ContentData::cell_unpack(Ref<vm::Cell> cell_ref, ContentData::Record_chunks& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool ContentData::cell_unpack_chunks(Ref<vm::Cell> cell_ref, Ref<CellSlice>& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_chunks(cs, data) && cs.empty_ext();
}

bool ContentData::pack(vm::CellBuilder& cb, const ContentData::Record_snake& data) const {
  return cb.store_long_bool(0, 8)
      && t_Anything.store_from(cb, data.data);
}

bool ContentData::pack_snake(vm::CellBuilder& cb, Ref<CellSlice> data) const {
  return cb.store_long_bool(0, 8)
      && t_Anything.store_from(cb, data);
}

bool ContentData::cell_pack(Ref<vm::Cell>& cell_ref, const ContentData::Record_snake& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool ContentData::cell_pack_snake(Ref<vm::Cell>& cell_ref, Ref<CellSlice> data) const {
  vm::CellBuilder cb;
  return pack_snake(cb, std::move(data)) && std::move(cb).finalize_to(cell_ref);
}

bool ContentData::pack(vm::CellBuilder& cb, const ContentData::Record_chunks& data) const {
  return cb.store_long_bool(1, 8)
      && t_ChunkedData.store_from(cb, data.data);
}

bool ContentData::pack_chunks(vm::CellBuilder& cb, Ref<CellSlice> data) const {
  return cb.store_long_bool(1, 8)
      && t_ChunkedData.store_from(cb, data);
}

bool ContentData::cell_pack(Ref<vm::Cell>& cell_ref, const ContentData::Record_chunks& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool ContentData::cell_pack_chunks(Ref<vm::Cell>& cell_ref, Ref<CellSlice> data) const {
  vm::CellBuilder cb;
  return pack_chunks(cb, std::move(data)) && std::move(cb).finalize_to(cell_ref);
}

bool ContentData::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case snake:
    return cs.fetch_ulong(8) == 0
        && pp.open("snake")
        && pp.field("data")
        && t_Anything.print_skip(pp, cs)
        && pp.close();
  case chunks:
    return cs.fetch_ulong(8) == 1
        && pp.open("chunks")
        && pp.field("data")
        && t_ChunkedData.print_skip(pp, cs)
        && pp.close();
  }
  return pp.fail("unknown constructor for ContentData");
}

const ContentData t_ContentData;

//
// code for type `FullContent`
//

int FullContent::get_tag(const vm::CellSlice& cs) const {
  switch (cs.bselect(6, 3)) {
  case 0:
    return cs.bit_at(7) ? offchain : onchain;
  default:
    return -1;
  }
}

int FullContent::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case onchain:
    return cs.prefetch_ulong(8) == 0 ? onchain : -1;
  case offchain:
    return cs.prefetch_ulong(8) == 1 ? offchain : -1;
  }
  return -1;
}

bool FullContent::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case onchain:
    return cs.advance(8)
        && t_HashmapE_256_Ref_ContentData.skip(cs);
  case offchain:
    return cs.advance(8)
        && t_Text.skip(cs);
  }
  return false;
}

bool FullContent::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case onchain:
    return cs.fetch_ulong(8) == 0
        && t_HashmapE_256_Ref_ContentData.validate_skip(ops, cs, weak);
  case offchain:
    return cs.fetch_ulong(8) == 1
        && t_Text.validate_skip(ops, cs, weak);
  }
  return false;
}

bool FullContent::unpack(vm::CellSlice& cs, FullContent::Record_onchain& data) const {
  return cs.fetch_ulong(8) == 0
      && t_HashmapE_256_Ref_ContentData.fetch_to(cs, data.data);
}

bool FullContent::unpack_onchain(vm::CellSlice& cs, Ref<CellSlice>& data) const {
  return cs.fetch_ulong(8) == 0
      && t_HashmapE_256_Ref_ContentData.fetch_to(cs, data);
}

bool FullContent::cell_unpack(Ref<vm::Cell> cell_ref, FullContent::Record_onchain& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool FullContent::cell_unpack_onchain(Ref<vm::Cell> cell_ref, Ref<CellSlice>& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_onchain(cs, data) && cs.empty_ext();
}

bool FullContent::unpack(vm::CellSlice& cs, FullContent::Record_offchain& data) const {
  return cs.fetch_ulong(8) == 1
      && t_Text.fetch_to(cs, data.uri);
}

bool FullContent::unpack_offchain(vm::CellSlice& cs, Ref<CellSlice>& uri) const {
  return cs.fetch_ulong(8) == 1
      && t_Text.fetch_to(cs, uri);
}

bool FullContent::cell_unpack(Ref<vm::Cell> cell_ref, FullContent::Record_offchain& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool FullContent::cell_unpack_offchain(Ref<vm::Cell> cell_ref, Ref<CellSlice>& uri) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_offchain(cs, uri) && cs.empty_ext();
}

bool FullContent::pack(vm::CellBuilder& cb, const FullContent::Record_onchain& data) const {
  return cb.store_long_bool(0, 8)
      && t_HashmapE_256_Ref_ContentData.store_from(cb, data.data);
}

bool FullContent::pack_onchain(vm::CellBuilder& cb, Ref<CellSlice> data) const {
  return cb.store_long_bool(0, 8)
      && t_HashmapE_256_Ref_ContentData.store_from(cb, data);
}

bool FullContent::cell_pack(Ref<vm::Cell>& cell_ref, const FullContent::Record_onchain& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool FullContent::cell_pack_onchain(Ref<vm::Cell>& cell_ref, Ref<CellSlice> data) const {
  vm::CellBuilder cb;
  return pack_onchain(cb, std::move(data)) && std::move(cb).finalize_to(cell_ref);
}

bool FullContent::pack(vm::CellBuilder& cb, const FullContent::Record_offchain& data) const {
  return cb.store_long_bool(1, 8)
      && t_Text.store_from(cb, data.uri);
}

bool FullContent::pack_offchain(vm::CellBuilder& cb, Ref<CellSlice> uri) const {
  return cb.store_long_bool(1, 8)
      && t_Text.store_from(cb, uri);
}

bool FullContent::cell_pack(Ref<vm::Cell>& cell_ref, const FullContent::Record_offchain& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool FullContent::cell_pack_offchain(Ref<vm::Cell>& cell_ref, Ref<CellSlice> uri) const {
  vm::CellBuilder cb;
  return pack_offchain(cb, std::move(uri)) && std::move(cb).finalize_to(cell_ref);
}

bool FullContent::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case onchain:
    return cs.fetch_ulong(8) == 0
        && pp.open("onchain")
        && pp.field("data")
        && t_HashmapE_256_Ref_ContentData.print_skip(pp, cs)
        && pp.close();
  case offchain:
    return cs.fetch_ulong(8) == 1
        && pp.open("offchain")
        && pp.field("uri")
        && t_Text.print_skip(pp, cs)
        && pp.close();
  }
  return pp.fail("unknown constructor for FullContent");
}

const FullContent t_FullContent;

//
// code for type `Protocol`
//
constexpr unsigned short Protocol::cons_tag[1];

int Protocol::check_tag(const vm::CellSlice& cs) const {
  return cs.prefetch_ulong(16) == 0x4854 ? proto_http : -1;
}

bool Protocol::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  return cs.fetch_ulong(16) == 0x4854;
}

bool Protocol::fetch_enum_to(vm::CellSlice& cs, char& value) const {
  value = (cs.fetch_ulong(16) == 0x4854) ? 0 : -1;
  return !value;
}

bool Protocol::store_enum_from(vm::CellBuilder& cb, int value) const {
  return !value && cb.store_long_bool(0x4854, 16);
}

bool Protocol::unpack(vm::CellSlice& cs, Protocol::Record& data) const {
  return cs.fetch_ulong(16) == 0x4854;
}

bool Protocol::unpack_proto_http(vm::CellSlice& cs) const {
  return cs.fetch_ulong(16) == 0x4854;
}

bool Protocol::cell_unpack(Ref<vm::Cell> cell_ref, Protocol::Record& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool Protocol::cell_unpack_proto_http(Ref<vm::Cell> cell_ref) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_proto_http(cs) && cs.empty_ext();
}

bool Protocol::pack(vm::CellBuilder& cb, const Protocol::Record& data) const {
  return cb.store_long_bool(0x4854, 16);
}

bool Protocol::pack_proto_http(vm::CellBuilder& cb) const {
  return cb.store_long_bool(0x4854, 16);
}

bool Protocol::cell_pack(Ref<vm::Cell>& cell_ref, const Protocol::Record& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool Protocol::cell_pack_proto_http(Ref<vm::Cell>& cell_ref) const {
  vm::CellBuilder cb;
  return pack_proto_http(cb) && std::move(cb).finalize_to(cell_ref);
}

bool Protocol::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  return cs.fetch_ulong(16) == 0x4854
      && pp.cons("proto_http");
}

const Protocol t_Protocol;

//
// code for type `ProtoList`
//

int ProtoList::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case proto_list_nil:
    return cs.have(1) ? proto_list_nil : -1;
  case proto_list_next:
    return cs.have(1) ? proto_list_next : -1;
  }
  return -1;
}

bool ProtoList::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case proto_list_nil:
    return cs.advance(1);
  case proto_list_next:
    return cs.advance(17)
        && skip(cs);
  }
  return false;
}

bool ProtoList::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case proto_list_nil:
    return cs.advance(1);
  case proto_list_next:
    return cs.advance(1)
        && t_Protocol.validate_skip(ops, cs, weak)
        && validate_skip(ops, cs, weak);
  }
  return false;
}

bool ProtoList::unpack(vm::CellSlice& cs, ProtoList::Record_proto_list_nil& data) const {
  return cs.fetch_ulong(1) == 0;
}

bool ProtoList::unpack_proto_list_nil(vm::CellSlice& cs) const {
  return cs.fetch_ulong(1) == 0;
}

bool ProtoList::cell_unpack(Ref<vm::Cell> cell_ref, ProtoList::Record_proto_list_nil& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool ProtoList::cell_unpack_proto_list_nil(Ref<vm::Cell> cell_ref) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_proto_list_nil(cs) && cs.empty_ext();
}

bool ProtoList::unpack(vm::CellSlice& cs, ProtoList::Record_proto_list_next& data) const {
  return cs.fetch_ulong(1) == 1
      && t_Protocol.fetch_enum_to(cs, data.head)
      && fetch_to(cs, data.tail);
}

bool ProtoList::unpack_proto_list_next(vm::CellSlice& cs, char& head, Ref<CellSlice>& tail) const {
  return cs.fetch_ulong(1) == 1
      && t_Protocol.fetch_enum_to(cs, head)
      && fetch_to(cs, tail);
}

bool ProtoList::cell_unpack(Ref<vm::Cell> cell_ref, ProtoList::Record_proto_list_next& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool ProtoList::cell_unpack_proto_list_next(Ref<vm::Cell> cell_ref, char& head, Ref<CellSlice>& tail) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_proto_list_next(cs, head, tail) && cs.empty_ext();
}

bool ProtoList::pack(vm::CellBuilder& cb, const ProtoList::Record_proto_list_nil& data) const {
  return cb.store_long_bool(0, 1);
}

bool ProtoList::pack_proto_list_nil(vm::CellBuilder& cb) const {
  return cb.store_long_bool(0, 1);
}

bool ProtoList::cell_pack(Ref<vm::Cell>& cell_ref, const ProtoList::Record_proto_list_nil& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool ProtoList::cell_pack_proto_list_nil(Ref<vm::Cell>& cell_ref) const {
  vm::CellBuilder cb;
  return pack_proto_list_nil(cb) && std::move(cb).finalize_to(cell_ref);
}

bool ProtoList::pack(vm::CellBuilder& cb, const ProtoList::Record_proto_list_next& data) const {
  return cb.store_long_bool(1, 1)
      && t_Protocol.store_enum_from(cb, data.head)
      && store_from(cb, data.tail);
}

bool ProtoList::pack_proto_list_next(vm::CellBuilder& cb, char head, Ref<CellSlice> tail) const {
  return cb.store_long_bool(1, 1)
      && t_Protocol.store_enum_from(cb, head)
      && store_from(cb, tail);
}

bool ProtoList::cell_pack(Ref<vm::Cell>& cell_ref, const ProtoList::Record_proto_list_next& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool ProtoList::cell_pack_proto_list_next(Ref<vm::Cell>& cell_ref, char head, Ref<CellSlice> tail) const {
  vm::CellBuilder cb;
  return pack_proto_list_next(cb, head, std::move(tail)) && std::move(cb).finalize_to(cell_ref);
}

bool ProtoList::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case proto_list_nil:
    return cs.advance(1)
        && pp.cons("proto_list_nil");
  case proto_list_next:
    return cs.advance(1)
        && pp.open("proto_list_next")
        && pp.field("head")
        && t_Protocol.print_skip(pp, cs)
        && pp.field("tail")
        && print_skip(pp, cs)
        && pp.close();
  }
  return pp.fail("unknown constructor for ProtoList");
}

const ProtoList t_ProtoList;

//
// code for type `SmcCapability`
//
constexpr unsigned short SmcCapability::cons_tag[1];

int SmcCapability::check_tag(const vm::CellSlice& cs) const {
  return cs.prefetch_ulong(16) == 0x2177 ? cap_is_wallet : -1;
}

bool SmcCapability::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  return cs.fetch_ulong(16) == 0x2177;
}

bool SmcCapability::fetch_enum_to(vm::CellSlice& cs, char& value) const {
  value = (cs.fetch_ulong(16) == 0x2177) ? 0 : -1;
  return !value;
}

bool SmcCapability::store_enum_from(vm::CellBuilder& cb, int value) const {
  return !value && cb.store_long_bool(0x2177, 16);
}

bool SmcCapability::unpack(vm::CellSlice& cs, SmcCapability::Record& data) const {
  return cs.fetch_ulong(16) == 0x2177;
}

bool SmcCapability::unpack_cap_is_wallet(vm::CellSlice& cs) const {
  return cs.fetch_ulong(16) == 0x2177;
}

bool SmcCapability::cell_unpack(Ref<vm::Cell> cell_ref, SmcCapability::Record& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool SmcCapability::cell_unpack_cap_is_wallet(Ref<vm::Cell> cell_ref) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_cap_is_wallet(cs) && cs.empty_ext();
}

bool SmcCapability::pack(vm::CellBuilder& cb, const SmcCapability::Record& data) const {
  return cb.store_long_bool(0x2177, 16);
}

bool SmcCapability::pack_cap_is_wallet(vm::CellBuilder& cb) const {
  return cb.store_long_bool(0x2177, 16);
}

bool SmcCapability::cell_pack(Ref<vm::Cell>& cell_ref, const SmcCapability::Record& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool SmcCapability::cell_pack_cap_is_wallet(Ref<vm::Cell>& cell_ref) const {
  vm::CellBuilder cb;
  return pack_cap_is_wallet(cb) && std::move(cb).finalize_to(cell_ref);
}

bool SmcCapability::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  return cs.fetch_ulong(16) == 0x2177
      && pp.cons("cap_is_wallet");
}

const SmcCapability t_SmcCapability;

//
// code for type `SmcCapList`
//

int SmcCapList::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case cap_list_nil:
    return cs.have(1) ? cap_list_nil : -1;
  case cap_list_next:
    return cs.have(1) ? cap_list_next : -1;
  }
  return -1;
}

bool SmcCapList::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case cap_list_nil:
    return cs.advance(1);
  case cap_list_next:
    return cs.advance(17)
        && skip(cs);
  }
  return false;
}

bool SmcCapList::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case cap_list_nil:
    return cs.advance(1);
  case cap_list_next:
    return cs.advance(1)
        && t_SmcCapability.validate_skip(ops, cs, weak)
        && validate_skip(ops, cs, weak);
  }
  return false;
}

bool SmcCapList::unpack(vm::CellSlice& cs, SmcCapList::Record_cap_list_nil& data) const {
  return cs.fetch_ulong(1) == 0;
}

bool SmcCapList::unpack_cap_list_nil(vm::CellSlice& cs) const {
  return cs.fetch_ulong(1) == 0;
}

bool SmcCapList::cell_unpack(Ref<vm::Cell> cell_ref, SmcCapList::Record_cap_list_nil& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool SmcCapList::cell_unpack_cap_list_nil(Ref<vm::Cell> cell_ref) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_cap_list_nil(cs) && cs.empty_ext();
}

bool SmcCapList::unpack(vm::CellSlice& cs, SmcCapList::Record_cap_list_next& data) const {
  return cs.fetch_ulong(1) == 1
      && t_SmcCapability.fetch_enum_to(cs, data.head)
      && fetch_to(cs, data.tail);
}

bool SmcCapList::unpack_cap_list_next(vm::CellSlice& cs, char& head, Ref<CellSlice>& tail) const {
  return cs.fetch_ulong(1) == 1
      && t_SmcCapability.fetch_enum_to(cs, head)
      && fetch_to(cs, tail);
}

bool SmcCapList::cell_unpack(Ref<vm::Cell> cell_ref, SmcCapList::Record_cap_list_next& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool SmcCapList::cell_unpack_cap_list_next(Ref<vm::Cell> cell_ref, char& head, Ref<CellSlice>& tail) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_cap_list_next(cs, head, tail) && cs.empty_ext();
}

bool SmcCapList::pack(vm::CellBuilder& cb, const SmcCapList::Record_cap_list_nil& data) const {
  return cb.store_long_bool(0, 1);
}

bool SmcCapList::pack_cap_list_nil(vm::CellBuilder& cb) const {
  return cb.store_long_bool(0, 1);
}

bool SmcCapList::cell_pack(Ref<vm::Cell>& cell_ref, const SmcCapList::Record_cap_list_nil& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool SmcCapList::cell_pack_cap_list_nil(Ref<vm::Cell>& cell_ref) const {
  vm::CellBuilder cb;
  return pack_cap_list_nil(cb) && std::move(cb).finalize_to(cell_ref);
}

bool SmcCapList::pack(vm::CellBuilder& cb, const SmcCapList::Record_cap_list_next& data) const {
  return cb.store_long_bool(1, 1)
      && t_SmcCapability.store_enum_from(cb, data.head)
      && store_from(cb, data.tail);
}

bool SmcCapList::pack_cap_list_next(vm::CellBuilder& cb, char head, Ref<CellSlice> tail) const {
  return cb.store_long_bool(1, 1)
      && t_SmcCapability.store_enum_from(cb, head)
      && store_from(cb, tail);
}

bool SmcCapList::cell_pack(Ref<vm::Cell>& cell_ref, const SmcCapList::Record_cap_list_next& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool SmcCapList::cell_pack_cap_list_next(Ref<vm::Cell>& cell_ref, char head, Ref<CellSlice> tail) const {
  vm::CellBuilder cb;
  return pack_cap_list_next(cb, head, std::move(tail)) && std::move(cb).finalize_to(cell_ref);
}

bool SmcCapList::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case cap_list_nil:
    return cs.advance(1)
        && pp.cons("cap_list_nil");
  case cap_list_next:
    return cs.advance(1)
        && pp.open("cap_list_next")
        && pp.field("head")
        && t_SmcCapability.print_skip(pp, cs)
        && pp.field("tail")
        && print_skip(pp, cs)
        && pp.close();
  }
  return pp.fail("unknown constructor for SmcCapList");
}

const SmcCapList t_SmcCapList;

//
// code for type `DNSRecord`
//
constexpr unsigned short DNSRecord::cons_tag[4];

int DNSRecord::check_tag(const vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case dns_smc_address:
    return cs.prefetch_ulong(16) == 0x9fd3 ? dns_smc_address : -1;
  case dns_next_resolver:
    return cs.prefetch_ulong(16) == 0xba93 ? dns_next_resolver : -1;
  case dns_adnl_address:
    return cs.prefetch_ulong(16) == 0xad01 ? dns_adnl_address : -1;
  case dns_storage_address:
    return cs.prefetch_ulong(16) == 0x7473 ? dns_storage_address : -1;
  }
  return -1;
}

bool DNSRecord::skip(vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case dns_smc_address: {
    int flags;
    return cs.advance(16)
        && t_MsgAddressInt.skip(cs)
        && cs.fetch_uint_to(8, flags)
        && flags <= 1
        && (!(flags & 1) || t_SmcCapList.skip(cs));
    }
  case dns_next_resolver:
    return cs.advance(16)
        && t_MsgAddressInt.skip(cs);
  case dns_adnl_address: {
    int flags;
    return cs.advance(272)
        && cs.fetch_uint_to(8, flags)
        && flags <= 1
        && (!(flags & 1) || t_ProtoList.skip(cs));
    }
  case dns_storage_address:
    return cs.advance(272);
  }
  return false;
}

bool DNSRecord::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  switch (get_tag(cs)) {
  case dns_smc_address: {
    int flags;
    return cs.fetch_ulong(16) == 0x9fd3
        && t_MsgAddressInt.validate_skip(ops, cs, weak)
        && cs.fetch_uint_to(8, flags)
        && flags <= 1
        && (!(flags & 1) || t_SmcCapList.validate_skip(ops, cs, weak));
    }
  case dns_next_resolver:
    return cs.fetch_ulong(16) == 0xba93
        && t_MsgAddressInt.validate_skip(ops, cs, weak);
  case dns_adnl_address: {
    int flags;
    return cs.fetch_ulong(16) == 0xad01
        && cs.advance(256)
        && cs.fetch_uint_to(8, flags)
        && flags <= 1
        && (!(flags & 1) || t_ProtoList.validate_skip(ops, cs, weak));
    }
  case dns_storage_address:
    return cs.fetch_ulong(16) == 0x7473
        && cs.advance(256);
  }
  return false;
}

bool DNSRecord::unpack(vm::CellSlice& cs, DNSRecord::Record_dns_smc_address& data) const {
  return cs.fetch_ulong(16) == 0x9fd3
      && t_MsgAddressInt.fetch_to(cs, data.smc_addr)
      && cs.fetch_uint_to(8, data.flags)
      && data.flags <= 1
      && (!(data.flags & 1) || t_SmcCapList.fetch_to(cs, data.cap_list));
}

bool DNSRecord::unpack_dns_smc_address(vm::CellSlice& cs, Ref<CellSlice>& smc_addr, int& flags, Ref<CellSlice>& cap_list) const {
  return cs.fetch_ulong(16) == 0x9fd3
      && t_MsgAddressInt.fetch_to(cs, smc_addr)
      && cs.fetch_uint_to(8, flags)
      && flags <= 1
      && (!(flags & 1) || t_SmcCapList.fetch_to(cs, cap_list));
}

bool DNSRecord::cell_unpack(Ref<vm::Cell> cell_ref, DNSRecord::Record_dns_smc_address& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool DNSRecord::cell_unpack_dns_smc_address(Ref<vm::Cell> cell_ref, Ref<CellSlice>& smc_addr, int& flags, Ref<CellSlice>& cap_list) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_dns_smc_address(cs, smc_addr, flags, cap_list) && cs.empty_ext();
}

bool DNSRecord::unpack(vm::CellSlice& cs, DNSRecord::Record_dns_next_resolver& data) const {
  return cs.fetch_ulong(16) == 0xba93
      && t_MsgAddressInt.fetch_to(cs, data.resolver);
}

bool DNSRecord::unpack_dns_next_resolver(vm::CellSlice& cs, Ref<CellSlice>& resolver) const {
  return cs.fetch_ulong(16) == 0xba93
      && t_MsgAddressInt.fetch_to(cs, resolver);
}

bool DNSRecord::cell_unpack(Ref<vm::Cell> cell_ref, DNSRecord::Record_dns_next_resolver& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool DNSRecord::cell_unpack_dns_next_resolver(Ref<vm::Cell> cell_ref, Ref<CellSlice>& resolver) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_dns_next_resolver(cs, resolver) && cs.empty_ext();
}

bool DNSRecord::unpack(vm::CellSlice& cs, DNSRecord::Record_dns_adnl_address& data) const {
  return cs.fetch_ulong(16) == 0xad01
      && cs.fetch_bits_to(data.adnl_addr.bits(), 256)
      && cs.fetch_uint_to(8, data.flags)
      && data.flags <= 1
      && (!(data.flags & 1) || t_ProtoList.fetch_to(cs, data.proto_list));
}

bool DNSRecord::unpack_dns_adnl_address(vm::CellSlice& cs, td::BitArray<256>& adnl_addr, int& flags, Ref<CellSlice>& proto_list) const {
  return cs.fetch_ulong(16) == 0xad01
      && cs.fetch_bits_to(adnl_addr.bits(), 256)
      && cs.fetch_uint_to(8, flags)
      && flags <= 1
      && (!(flags & 1) || t_ProtoList.fetch_to(cs, proto_list));
}

bool DNSRecord::cell_unpack(Ref<vm::Cell> cell_ref, DNSRecord::Record_dns_adnl_address& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool DNSRecord::cell_unpack_dns_adnl_address(Ref<vm::Cell> cell_ref, td::BitArray<256>& adnl_addr, int& flags, Ref<CellSlice>& proto_list) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_dns_adnl_address(cs, adnl_addr, flags, proto_list) && cs.empty_ext();
}

bool DNSRecord::unpack(vm::CellSlice& cs, DNSRecord::Record_dns_storage_address& data) const {
  return cs.fetch_ulong(16) == 0x7473
      && cs.fetch_bits_to(data.bag_id.bits(), 256);
}

bool DNSRecord::unpack_dns_storage_address(vm::CellSlice& cs, td::BitArray<256>& bag_id) const {
  return cs.fetch_ulong(16) == 0x7473
      && cs.fetch_bits_to(bag_id.bits(), 256);
}

bool DNSRecord::cell_unpack(Ref<vm::Cell> cell_ref, DNSRecord::Record_dns_storage_address& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool DNSRecord::cell_unpack_dns_storage_address(Ref<vm::Cell> cell_ref, td::BitArray<256>& bag_id) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_dns_storage_address(cs, bag_id) && cs.empty_ext();
}

bool DNSRecord::pack(vm::CellBuilder& cb, const DNSRecord::Record_dns_smc_address& data) const {
  return cb.store_long_bool(0x9fd3, 16)
      && t_MsgAddressInt.store_from(cb, data.smc_addr)
      && cb.store_ulong_rchk_bool(data.flags, 8)
      && data.flags <= 1
      && (!(data.flags & 1) || t_SmcCapList.store_from(cb, data.cap_list));
}

bool DNSRecord::pack_dns_smc_address(vm::CellBuilder& cb, Ref<CellSlice> smc_addr, int flags, Ref<CellSlice> cap_list) const {
  return cb.store_long_bool(0x9fd3, 16)
      && t_MsgAddressInt.store_from(cb, smc_addr)
      && cb.store_ulong_rchk_bool(flags, 8)
      && flags <= 1
      && (!(flags & 1) || t_SmcCapList.store_from(cb, cap_list));
}

bool DNSRecord::cell_pack(Ref<vm::Cell>& cell_ref, const DNSRecord::Record_dns_smc_address& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool DNSRecord::cell_pack_dns_smc_address(Ref<vm::Cell>& cell_ref, Ref<CellSlice> smc_addr, int flags, Ref<CellSlice> cap_list) const {
  vm::CellBuilder cb;
  return pack_dns_smc_address(cb, std::move(smc_addr), flags, std::move(cap_list)) && std::move(cb).finalize_to(cell_ref);
}

bool DNSRecord::pack(vm::CellBuilder& cb, const DNSRecord::Record_dns_next_resolver& data) const {
  return cb.store_long_bool(0xba93, 16)
      && t_MsgAddressInt.store_from(cb, data.resolver);
}

bool DNSRecord::pack_dns_next_resolver(vm::CellBuilder& cb, Ref<CellSlice> resolver) const {
  return cb.store_long_bool(0xba93, 16)
      && t_MsgAddressInt.store_from(cb, resolver);
}

bool DNSRecord::cell_pack(Ref<vm::Cell>& cell_ref, const DNSRecord::Record_dns_next_resolver& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool DNSRecord::cell_pack_dns_next_resolver(Ref<vm::Cell>& cell_ref, Ref<CellSlice> resolver) const {
  vm::CellBuilder cb;
  return pack_dns_next_resolver(cb, std::move(resolver)) && std::move(cb).finalize_to(cell_ref);
}

bool DNSRecord::pack(vm::CellBuilder& cb, const DNSRecord::Record_dns_adnl_address& data) const {
  return cb.store_long_bool(0xad01, 16)
      && cb.store_bits_bool(data.adnl_addr.cbits(), 256)
      && cb.store_ulong_rchk_bool(data.flags, 8)
      && data.flags <= 1
      && (!(data.flags & 1) || t_ProtoList.store_from(cb, data.proto_list));
}

bool DNSRecord::pack_dns_adnl_address(vm::CellBuilder& cb, td::BitArray<256> adnl_addr, int flags, Ref<CellSlice> proto_list) const {
  return cb.store_long_bool(0xad01, 16)
      && cb.store_bits_bool(adnl_addr.cbits(), 256)
      && cb.store_ulong_rchk_bool(flags, 8)
      && flags <= 1
      && (!(flags & 1) || t_ProtoList.store_from(cb, proto_list));
}

bool DNSRecord::cell_pack(Ref<vm::Cell>& cell_ref, const DNSRecord::Record_dns_adnl_address& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool DNSRecord::cell_pack_dns_adnl_address(Ref<vm::Cell>& cell_ref, td::BitArray<256> adnl_addr, int flags, Ref<CellSlice> proto_list) const {
  vm::CellBuilder cb;
  return pack_dns_adnl_address(cb, adnl_addr, flags, std::move(proto_list)) && std::move(cb).finalize_to(cell_ref);
}

bool DNSRecord::pack(vm::CellBuilder& cb, const DNSRecord::Record_dns_storage_address& data) const {
  return cb.store_long_bool(0x7473, 16)
      && cb.store_bits_bool(data.bag_id.cbits(), 256);
}

bool DNSRecord::pack_dns_storage_address(vm::CellBuilder& cb, td::BitArray<256> bag_id) const {
  return cb.store_long_bool(0x7473, 16)
      && cb.store_bits_bool(bag_id.cbits(), 256);
}

bool DNSRecord::cell_pack(Ref<vm::Cell>& cell_ref, const DNSRecord::Record_dns_storage_address& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool DNSRecord::cell_pack_dns_storage_address(Ref<vm::Cell>& cell_ref, td::BitArray<256> bag_id) const {
  vm::CellBuilder cb;
  return pack_dns_storage_address(cb, bag_id) && std::move(cb).finalize_to(cell_ref);
}

bool DNSRecord::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  switch (get_tag(cs)) {
  case dns_smc_address: {
    int flags;
    return cs.fetch_ulong(16) == 0x9fd3
        && pp.open("dns_smc_address")
        && pp.field("smc_addr")
        && t_MsgAddressInt.print_skip(pp, cs)
        && cs.fetch_uint_to(8, flags)
        && pp.field_int(flags, "flags")
        && flags <= 1
        && (!(flags & 1) || (pp.field("cap_list") && t_SmcCapList.print_skip(pp, cs)))
        && pp.close();
    }
  case dns_next_resolver:
    return cs.fetch_ulong(16) == 0xba93
        && pp.open("dns_next_resolver")
        && pp.field("resolver")
        && t_MsgAddressInt.print_skip(pp, cs)
        && pp.close();
  case dns_adnl_address: {
    int flags;
    return cs.fetch_ulong(16) == 0xad01
        && pp.open("dns_adnl_address")
        && pp.fetch_bits_field(cs, 256, "adnl_addr")
        && cs.fetch_uint_to(8, flags)
        && pp.field_int(flags, "flags")
        && flags <= 1
        && (!(flags & 1) || (pp.field("proto_list") && t_ProtoList.print_skip(pp, cs)))
        && pp.close();
    }
  case dns_storage_address:
    return cs.fetch_ulong(16) == 0x7473
        && pp.open("dns_storage_address")
        && pp.fetch_bits_field(cs, 256, "bag_id")
        && pp.close();
  }
  return pp.fail("unknown constructor for DNSRecord");
}

const DNSRecord t_DNSRecord;

//
// code for type `DNS_RecordSet`
//

int DNS_RecordSet::check_tag(const vm::CellSlice& cs) const {
  return cons1;
}

bool DNS_RecordSet::skip(vm::CellSlice& cs) const {
  return t_HashmapE_256_Ref_DNSRecord.skip(cs);
}

bool DNS_RecordSet::validate_skip(int* ops, vm::CellSlice& cs, bool weak) const {
  return t_HashmapE_256_Ref_DNSRecord.validate_skip(ops, cs, weak);
}

bool DNS_RecordSet::unpack(vm::CellSlice& cs, DNS_RecordSet::Record& data) const {
  return t_HashmapE_256_Ref_DNSRecord.fetch_to(cs, data.x);
}

bool DNS_RecordSet::unpack_cons1(vm::CellSlice& cs, Ref<CellSlice>& x) const {
  return t_HashmapE_256_Ref_DNSRecord.fetch_to(cs, x);
}

bool DNS_RecordSet::cell_unpack(Ref<vm::Cell> cell_ref, DNS_RecordSet::Record& data) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack(cs, data) && cs.empty_ext();
}

bool DNS_RecordSet::cell_unpack_cons1(Ref<vm::Cell> cell_ref, Ref<CellSlice>& x) const {
  if (cell_ref.is_null()) { return false; }
  auto cs = load_cell_slice(std::move(cell_ref));
  return unpack_cons1(cs, x) && cs.empty_ext();
}

bool DNS_RecordSet::pack(vm::CellBuilder& cb, const DNS_RecordSet::Record& data) const {
  return t_HashmapE_256_Ref_DNSRecord.store_from(cb, data.x);
}

bool DNS_RecordSet::pack_cons1(vm::CellBuilder& cb, Ref<CellSlice> x) const {
  return t_HashmapE_256_Ref_DNSRecord.store_from(cb, x);
}

bool DNS_RecordSet::cell_pack(Ref<vm::Cell>& cell_ref, const DNS_RecordSet::Record& data) const {
  vm::CellBuilder cb;
  return pack(cb, data) && std::move(cb).finalize_to(cell_ref);
}

bool DNS_RecordSet::cell_pack_cons1(Ref<vm::Cell>& cell_ref, Ref<CellSlice> x) const {
  vm::CellBuilder cb;
  return pack_cons1(cb, std::move(x)) && std::move(cb).finalize_to(cell_ref);
}

bool DNS_RecordSet::print_skip(PrettyPrinter& pp, vm::CellSlice& cs) const {
  return pp.open()
      && pp.field()
      && t_HashmapE_256_Ref_DNSRecord.print_skip(pp, cs)
      && pp.close();
}

const DNS_RecordSet t_DNS_RecordSet;

// definitions of constant types used

const NatWidth t_natwidth_9{9};
const NatLeq t_natleq_30{30};
const Maybe t_Maybe_Anycast{t_Anycast};
const Int t_int8{8};
const Bits t_bits256{256};
const Int t_int32{32};
const UInt t_uint64{64};
const VarUInteger t_VarUInteger_16{16};
const Maybe t_Maybe_Ref_Cell{t_RefCell};
const Either t_Either_Cell_Ref_Cell{t_Anything, t_RefCell};
const NatWidth t_natwidth_1{1};
const HashmapE t_HashmapE_32_Ref_Cell{32, t_RefCell};
const RefT t_Ref_ContentData{t_ContentData};
const HashmapE t_HashmapE_256_Ref_ContentData{256, t_Ref_ContentData};
const NatWidth t_natwidth_8{8};
const RefT t_Ref_DNSRecord{t_DNSRecord};
const HashmapE t_HashmapE_256_Ref_DNSRecord{256, t_Ref_DNSRecord};

// definition of type name registration function
bool register_simple_types(std::function<bool(const char*, const TLB*)> func) {
  return func("MsgAddressExt", &t_MsgAddressExt)
      && func("Anycast", &t_Anycast)
      && func("MsgAddressInt", &t_MsgAddressInt)
      && func("MsgAddress", &t_MsgAddress)
      && func("InternalMsgBody", &t_InternalMsgBody)
      && func("Bit", &t_Bit)
      && func("Unary", &t_Unary)
      && func("ChunkedData", &t_ChunkedData)
      && func("Text", &t_Text)
      && func("ContentData", &t_ContentData)
      && func("FullContent", &t_FullContent)
      && func("Protocol", &t_Protocol)
      && func("ProtoList", &t_ProtoList)
      && func("SmcCapability", &t_SmcCapability)
      && func("SmcCapList", &t_SmcCapList)
      && func("DNSRecord", &t_DNSRecord)
      && func("DNS_RecordSet", &t_DNS_RecordSet);
}


} // namespace gen

} // namespace tokens
