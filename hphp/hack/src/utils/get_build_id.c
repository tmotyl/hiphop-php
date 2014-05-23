#include <caml/memory.h>
#include <caml/alloc.h>
#include <string.h>

extern const char* const BuildInfo_kRevision;
extern const char* const BuildInfo_kTimeISO8601;

/**
 * Export the constants provided by Facebook's build system to ocaml-land, since
 * their FFI only allows you to call functions, not reference variables. Doing
 * it this way makes sense for Facebook internally since our build system has
 * machinery for providing these two constants automatically (and no machinery
 * for doing codegen in a consistent way to build an ocaml file with them) but
 * is very roundabout for external users who have to have CMake codegen these
 * constants anyways. Sorry about that.
 */
value hh_get_build_id(void) {
  CAMLparam0();
  CAMLlocal1(result);

  size_t revlen = strlen(BuildInfo_kRevision);
  size_t timelen = strlen(BuildInfo_kTimeISO8601);
  result = caml_alloc_string(revlen + timelen + 1);

  memcpy(String_val(result), BuildInfo_kRevision, revlen);
  String_val(result)[revlen] = '-';
  memcpy(String_val(result) + revlen + 1, BuildInfo_kTimeISO8601, timelen);

  CAMLreturn(result);
}
