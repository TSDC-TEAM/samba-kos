set(TARGET_NAME hcrypto)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/aes.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/bn.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/dh.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/dh-ltm.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/des.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/dsa.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/engine.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/md2.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/md4.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/md5.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/rsa.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/rsa-ltm.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/rc2.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/rc4.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/rijndael-alg-fst.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/rnd_keys.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/sha.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/sha256.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/sha512.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/ui.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/evp.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/evp-hcrypto.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/pkcs5.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/pkcs12.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/rand.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/rand-egd.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/rand-unix.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/rand-fortuna.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/rand-timer.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/hmac.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/camellia.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/camellia-ntt.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/common.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/validate.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bncore.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_init.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_clear.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_exch.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_grow.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_shrink.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_clamp.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_zero.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_zero_multi.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_set.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_set_int.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_init_size.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_copy.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_init_copy.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_abs.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_neg.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_cmp_mag.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_cmp.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_cmp_d.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_rshd.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_lshd.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_mod_2d.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_div_2d.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_mul_2d.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_div_2.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_mul_2.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_s_mp_add.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_s_mp_sub.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_fast_s_mp_mul_digs.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_s_mp_mul_digs.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_fast_s_mp_mul_high_digs.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_s_mp_mul_high_digs.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_fast_s_mp_sqr.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_s_mp_sqr.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_add.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_sub.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_karatsuba_mul.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_mul.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_karatsuba_sqr.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_sqr.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_div.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_mod.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_add_d.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_sub_d.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_mul_d.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_div_d.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_mod_d.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_expt_d.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_addmod.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_submod.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_mulmod.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_sqrmod.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_gcd.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_lcm.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_fast_mp_invmod.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_invmod.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_reduce.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_montgomery_setup.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_fast_mp_montgomery_reduce.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_montgomery_reduce.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_exptmod_fast.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_exptmod.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_2expt.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_n_root.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_jacobi.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_reverse.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_count_bits.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_read_unsigned_bin.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_read_signed_bin.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_to_unsigned_bin.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_to_signed_bin.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_unsigned_bin_size.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_signed_bin_size.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_xor.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_and.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_or.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_rand.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_montgomery_calc_normalization.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_prime_is_divisible.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_prime_tab.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_prime_fermat.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_prime_miller_rabin.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_prime_is_prime.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_prime_next_prime.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_find_prime.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_isprime.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_dr_reduce.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_dr_is_modulus.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_dr_setup.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_reduce_setup.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_toom_mul.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_toom_sqr.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_div_3.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_s_mp_exptmod.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_reduce_2k.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_reduce_is_2k.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_reduce_2k_setup.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_reduce_2k_l.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_reduce_is_2k_l.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_reduce_2k_setup_l.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_radix_smap.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_read_radix.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_toradix.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_radix_size.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_fread.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_fwrite.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_cnt_lsb.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_error.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_init_multi.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_clear_multi.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_exteuclid.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_toradix_n.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_prime_random_ex.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_get_int.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_sqrt.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_is_square.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_init_set.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_init_set_int.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_invmod_slow.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_prime_rabin_miller_trials.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_to_signed_bin_n.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath/bn_mp_to_unsigned_bin_n.c
        )

add_library(
        ${TARGET_NAME}_obj
        OBJECT
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}_obj
        PRIVATE
        ${SMB_SRC_ROOT}/source4/heimdal_build
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal_build
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hcrypto
        ${SMB_SRC_ROOT}/source4/heimdal/lib
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib
        ${SMB_SRC_ROOT}/source4/heimdal/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/include
        ${SMB_SRC_ROOT}/include/public
        ${SMB_SRC_ROOT}/bin/default/include/public
        ${SMB_SRC_ROOT}/source4
        ${SMB_SRC_ROOT}/bin/default/source4
        ${SMB_SRC_ROOT}/lib
        ${SMB_SRC_ROOT}/bin/default/lib
        ${SMB_SRC_ROOT}/source4/lib
        ${SMB_SRC_ROOT}/bin/default/source4/lib
        ${SMB_SRC_ROOT}/source4/include
        ${SMB_SRC_ROOT}/bin/default/source4/include
        ${SMB_SRC_ROOT}/include
        ${SMB_SRC_ROOT}/bin/default/include
        ${SMB_SRC_ROOT}/lib/replace
        ${SMB_SRC_ROOT}/bin/default/lib/replace
        ${SMB_SRC_ROOT}/.
        ${SMB_SRC_ROOT}/bin/default/
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hcrypto/libtommath
        ${SMB_SRC_ROOT}/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/source4/heimdal/lib/com_err
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/com_err
)

target_compile_definitions(
        ${TARGET_NAME}_obj
        PRIVATE
        _SAMBA_BUILD_=4
        HAVE_CONFIG_H=1
        _GNU_SOURCE=1
        _XOPEN_SOURCE_EXTENDED=1
        __STDC_WANT_LIB_EXT1__=1
        _REENTRANT
        _POSIX_PTHREAD_SEMANTICS
        STATIC_hcrypto_MODULES=NULL
        "STATIC_hcrypto_MODULES_PROTO=extern void __hcrypto_dummy_module_proto(void)"
        STATIC_tommath_MODULES=NULL
        "STATIC_tommath_MODULES_PROTO=extern void __tommath_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}_obj
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
        -Wno-error=discarded-qualifiers
        -Wno-error=cast-qual
        -Wno-error=missing-field-initializers
        -Wno-error=shadow
        -Wno-error=implicit-fallthrough
        -Wno-error=enum-compare
        -Wno-error=unused-but-set-variable
        -Wno-error=unused-const-variable
        -Wno-error=unused-variable
        -Wno-error=unused-result
)
