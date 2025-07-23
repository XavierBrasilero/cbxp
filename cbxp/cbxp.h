#ifndef __CBXP_H_
#define __CBXP_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
This is the main interface to CBXP.

The following pointers must be freed after calling this interface to
avoid memory leaks:

  result.result_json

*/
void cbxp(char *result_json, const char *request_json, bool debug);

#ifdef __cplusplus
}
#endif

#pragma export(cbxp)

#endif
