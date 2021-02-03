DIST_SUBDIRS = secp256k1
AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS)


if EMBEDDED_LEVELDB
LEVELDB_CPPFLAGS += -I$(srcdir)/leveldb/include
LEVELDB_CPPFLAGS += -I$(srcdir)/leveldb/helpers/memenv
LIBLEVELDB += $(builddir)/leveldb/libleveldb.a
LIBMEMENV  += $(builddir)/leveldb/libmemenv.a

# NOTE: This dependency is not strictly necessary, but without it make may try to build both in parallel, which breaks the LevelDB build system in a race
$(LIBLEVELDB): $(LIBMEMENV)

$(LIBLEVELDB) $(LIBMEMENV):
	@echo "Building LevelDB ..." && $(MAKE) -C $(@D) $(@F) CXX="$(CXX)" \
	  CC="$(CC)" PLATFORM=$(TARGET_OS) AR="$(AR)" $(LEVELDB_TARGET_FLAGS) \
          OPT="$(CXXFLAGS) $(CPPFLAGS)"
endif

SUNLIGHTCOIN_CONFIG_INCLUDES=-I$(builddir)/config
SUNLIGHTCOIN_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

SUNLIGHTCOIN_INCLUDES += -I$(srcdir)/secp256k1/include

LIBSUNLIGHTCOIN_SERVER=libsunlightcoin_server.a
LIBSUNLIGHTCOIN_WALLET=libsunlightcoin_wallet.a
LIBSUNLIGHTCOIN_COMMON=libsunlightcoin_common.a
LIBSUNLIGHTCOIN_CLI=libsunlightcoin_cli.a
LIBSUNLIGHTCOIN_UTIL=libsunlightcoin_util.a
LIBSUNLIGHTCOIN_CRYPTO=crypto/libsunlightcoin_crypto.a
LIBSUNLIGHTCOIN_UNIVALUE=univalue/libsunlightcoin_univalue.a
LIBSUNLIGHTCOINQT=qt/libsunlightcoinqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la

$(LIBSECP256K1): $(wildcard secp256k1/src/*) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES = \
  crypto/libsunlightcoin_crypto.a \
  libsunlightcoin_util.a \
  libsunlightcoin_common.a \
  univalue/libsunlightcoin_univalue.a \
  libsunlightcoin_server.a \
  libsunlightcoin_cli.a
if ENABLE_WALLET
SUNLIGHTCOIN_INCLUDES += $(BDB_CPPFLAGS)
EXTRA_LIBRARIES += libsunlightcoin_wallet.a
endif

if BUILD_SUNLIGHTCOIN_LIBS
lib_LTLIBRARIES = libsunlightcoinconsensus.la
LIBSUNLIGHTCOIN_CONSENSUS=libsunlightcoinconsensus.la
else
LIBSUNLIGHTCOIN_CONSENSUS=
endif

bin_PROGRAMS =
TESTS =

if BUILD_SUNLIGHTCOIND
  bin_PROGRAMS += sunlightcoind
endif

if BUILD_SUNLIGHTCOIN_UTILS
  bin_PROGRAMS += sunlightcoin-cli sunlightcoin-tx
endif

.PHONY: FORCE
# sunlightcoin core #
SUNLIGHTCOIN_CORE_H = \
  addrman.h \
  alert.h \
  allocators.h \
  amount.h \
  arith_uint256.h \
  base58.h \
  bloom.h \
  chain.h \
  chainparamsbase.h \
  chainparams.h \
  chainparamsseeds.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coincontrol.h \
  coins.h \
  compat.h \
  compressor.h \
  core_io.h \
  crypter.h \
  db.h \
  eccryptoverify.h \
  ecwrapper.h \
  hash.h \
  init.h \
  key.h \
  keystore.h \
  leveldbwrapper.h \
  limitedmap.h \
  main.h \
  merkleblock.h \
  miner.h \
  mruset.h \
  netbase.h \
  net.h \
  noui.h \
  pow.h \
  primitives/block.h \
  primitives/transaction.h \
  protocol.h \
  pubkey.h \
  random.h \
  rpcclient.h \
  rpcprotocol.h \
  rpcserver.h \
  script/interpreter.h \
  script/script_error.h \
  script/script.h \
  script/sigcache.h \
  script/sign.h \
  script/standard.h \
  serialize.h \
  streams.h \
  sync.h \
  threadsafety.h \
  timedata.h \
  tinyformat.h \
  txdb.h \
  txmempool.h \
  ui_interface.h \
  uint256.h \
  undo.h \
  util.h \
  utilmoneystr.h \
  utilstrencodings.h \
  utiltime.h \
  version.h \
  walletdb.h \
  wallet.h \
  wallet_ismine.h \
  compat/sanity.h

JSON_H = \
  json/json_spirit.h \
  json/json_spirit_error_position.h \
  json/json_spirit_reader.h \
  json/json_spirit_reader_template.h \
  json/json_spirit_stream_reader.h \
  json/json_spirit_utils.h \
  json/json_spirit_value.h \
  json/json_spirit_writer.h \
  json/json_spirit_writer_template.h
  
obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh $(abs_top_builddir)/src/obj/build.h \
	  $(abs_top_srcdir)
libsunlightcoin_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between sunlightcoind and sunlightcoin-qt
libsunlightcoin_server_a_CPPFLAGS = $(SUNLIGHTCOIN_INCLUDES) $(MINIUPNPC_CPPFLAGS)
libsunlightcoin_server_a_SOURCES = \
  addrman.cpp \
  alert.cpp \
  bloom.cpp \
  chain.cpp \
  checkpoints.cpp \
  init.cpp \
  leveldbwrapper.cpp \
  main.cpp \
  merkleblock.cpp \
  miner.cpp \
  net.cpp \
  noui.cpp \
  pow.cpp \
  rest.cpp \
  rpcblockchain.cpp \
  rpcmining.cpp \
  rpcmisc.cpp \
  rpcnet.cpp \
  rpcrawtransaction.cpp \
  rpcserver.cpp \
  script/sigcache.cpp \
  timedata.cpp \
  txdb.cpp \
  txmempool.cpp \
  $(JSON_H) \
  $(SUNLIGHTCOIN_CORE_H)

# wallet: shared between sunlightcoind and sunlightcoin-qt, but only linked
# when wallet enabled
libsunlightcoin_wallet_a_CPPFLAGS = $(SUNLIGHTCOIN_INCLUDES)
libsunlightcoin_wallet_a_SOURCES = \
  db.cpp \
  crypter.cpp \
  rpcdump.cpp \
  rpcwallet.cpp \
  wallet.cpp \
  wallet_ismine.cpp \
  walletdb.cpp \
  $(SUNLIGHTCOIN_CORE_H)

# crypto primitives library
crypto_libsunlightcoin_crypto_a_CPPFLAGS = $(SUNLIGHTCOIN_CONFIG_INCLUDES) $(KECCAK_INCLUDES)
crypto_libsunlightcoin_crypto_a_SOURCES = \
  crypto/sha1.cpp \
  crypto/sha256.cpp \
  crypto/sha512.cpp \
  crypto/hmac_sha256.cpp \
  crypto/rfc6979_hmac_sha256.cpp \
  crypto/hmac_sha512.cpp \
  crypto/ripemd160.cpp \
  crypto/common.h \
  crypto/sha256.h \
  crypto/sha512.h \
  crypto/hmac_sha256.h \
  crypto/rfc6979_hmac_sha256.h \
  crypto/hmac_sha512.h \
  crypto/sha1.h \
  crypto/scrypt.h \
  crypto/scrypt.cpp \
  crypto/keccak256.h \
  crypto/keccak256.cpp \
  crypto/ripemd160.h

# univalue JSON library
univalue_libsunlightcoin_univalue_a_SOURCES = \
  univalue/univalue.cpp \
  univalue/univalue_read.cpp \
  univalue/univalue_write.cpp \
  univalue/univalue_escapes.h \
  univalue/univalue.h

# common: shared between sunlightcoind, and sunlightcoin-qt and non-server tools
libsunlightcoin_common_a_CPPFLAGS = $(SUNLIGHTCOIN_INCLUDES)
libsunlightcoin_common_a_SOURCES = \
  allocators.cpp \
  arith_uint256.cpp \
  amount.cpp \
  base58.cpp \
  chainparams.cpp \
  coins.cpp \
  compressor.cpp \
  primitives/block.cpp \
  primitives/transaction.cpp \
  core_read.cpp \
  core_write.cpp \
  eccryptoverify.cpp \
  ecwrapper.cpp \
  hash.cpp \
  key.cpp \
  keystore.cpp \
  netbase.cpp \
  protocol.cpp \
  pubkey.cpp \
  script/interpreter.cpp \
  script/script.cpp \
  script/sign.cpp \
  script/standard.cpp \
  script/script_error.cpp \
  $(SUNLIGHTCOIN_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libsunlightcoin_util_a_CPPFLAGS = $(SUNLIGHTCOIN_INCLUDES)
libsunlightcoin_util_a_SOURCES = \
  chainparamsbase.cpp \
  clientversion.cpp \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  compat/strnlen.cpp \
  random.cpp \
  rpcprotocol.cpp \
  sync.cpp \
  uint256.cpp \
  util.cpp \
  utilmoneystr.cpp \
  utilstrencodings.cpp \
  utiltime.cpp \
  $(SUNLIGHTCOIN_CORE_H)

if GLIBC_BACK_COMPAT
libsunlightcoin_util_a_SOURCES += compat/glibc_compat.cpp
libsunlightcoin_util_a_SOURCES += compat/glibcxx_compat.cpp
endif

# cli: shared between sunlightcoin-cli and sunlightcoin-qt
libsunlightcoin_cli_a_CPPFLAGS = $(SUNLIGHTCOIN_INCLUDES)
libsunlightcoin_cli_a_SOURCES = \
  rpcclient.cpp \
  $(SUNLIGHTCOIN_CORE_H)

nodist_libsunlightcoin_util_a_SOURCES = $(srcdir)/obj/build.h
#

# sunlightcoind binary #
sunlightcoind_LDADD = \
  $(LIBSUNLIGHTCOIN_SERVER) \
  $(LIBSUNLIGHTCOIN_COMMON) \
  $(LIBSUNLIGHTCOIN_UNIVALUE) \
  $(LIBSUNLIGHTCOIN_UTIL) \
  $(LIBSUNLIGHTCOIN_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

if ENABLE_WALLET
sunlightcoind_LDADD += libsunlightcoin_wallet.a
endif
sunlightcoind_SOURCES = sunlightcoind.cpp
#

if TARGET_WINDOWS
sunlightcoind_SOURCES += sunlightcoind-res.rc
endif

sunlightcoind_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS)
sunlightcoind_CPPFLAGS = $(SUNLIGHTCOIN_INCLUDES)
sunlightcoind_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

# sunlightcoin-cli binary #
sunlightcoin_cli_LDADD = \
  $(LIBSUNLIGHTCOIN_CLI) \
  $(LIBSUNLIGHTCOIN_UTIL) \
  $(BOOST_LIBS) \
  $(SSL_LIBS) \
  $(CRYPTO_LIBS)

sunlightcoin_cli_SOURCES = \
  sunlightcoin-cli.cpp

sunlightcoin_cli_CPPFLAGS = $(SUNLIGHTCOIN_INCLUDES)
#

# sunlightcoin-tx binary #
sunlightcoin_tx_LDADD = \
  $(LIBSUNLIGHTCOIN_UNIVALUE) \
  $(LIBSUNLIGHTCOIN_COMMON) \
  $(LIBSUNLIGHTCOIN_UTIL) \
  $(LIBSUNLIGHTCOIN_CRYPTO) \
  $(LIBSECP256K1) \
  $(BOOST_LIBS) \
  $(CRYPTO_LIBS)

sunlightcoin_tx_SOURCES = sunlightcoin-tx.cpp
sunlightcoin_tx_CPPFLAGS = $(SUNLIGHTCOIN_INCLUDES)
#
sunlightcoin_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
sunlightcoin_cli_SOURCES += sunlightcoin-cli-res.rc
endif
sunlightcoin_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if BUILD_SUNLIGHTCOIN_LIBS
include_HEADERS = script/sunlightcoinconsensus.h
libsunlightcoinconsensus_la_SOURCES = \
  crypto/hmac_sha512.cpp \
  crypto/ripemd160.cpp \
  crypto/sha1.cpp \
  crypto/sha256.cpp \
  crypto/sha512.cpp \
  crypto/scrypt.cpp \
  crypto/keccak256.cpp \
  eccryptoverify.cpp \
  ecwrapper.cpp \
  hash.cpp \
  primitives/transaction.cpp \
  pubkey.cpp \
  script/sunlightcoinconsensus.cpp \
  script/interpreter.cpp \
  script/script.cpp \
  uint256.cpp \
  utilstrencodings.cpp

if GLIBC_BACK_COMPAT
  libsunlightcoinconsensus_la_SOURCES += compat/glibc_compat.cpp
  libsunlightcoinconsensus_la_SOURCES += compat/glibcxx_compat.cpp
endif

libsunlightcoinconsensus_la_LDFLAGS = -no-undefined $(RELDFLAGS)
libsunlightcoinconsensus_la_LIBADD = $(CRYPTO_LIBS)
libsunlightcoinconsensus_la_CPPFLAGS = $(CRYPTO_CFLAGS) -I$(builddir)/obj -DBUILD_SUNLIGHTCOIN_INTERNAL
if USE_LIBSECP256K1
libsunlightcoinconsensus_la_LIBADD += secp256k1/libsecp256k1.la
endif
endif

CLEANFILES = leveldb/libleveldb.a leveldb/libmemenv.a *.gcda *.gcno

DISTCLEANFILES = obj/build.h

EXTRA_DIST = leveldb

clean-local:
	-$(MAKE) -C leveldb clean
	-$(MAKE) -C secp256k1 clean
	rm -f leveldb/*/*.gcno leveldb/helpers/memenv/*.gcno
	-rm -f config.h

.rc.o:
	@test -f $(WINDRES)
	$(AM_V_GEN) $(WINDRES) -DWINDRES_PREPROC -i $< -o $@

.mm.o:
	$(AM_V_CXX) $(OBJCXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	  $(CPPFLAGS) $(AM_CXXFLAGS) $(QT_INCLUDES) $(CXXFLAGS)  -c -o $@ $<

%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(abspath $(<D) $<)

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
