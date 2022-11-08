

#include <mcheck.h>
#include <unistd.h>

#include <node_api.h>

// Node native API docs: https://nodejs.org/api/n-api.html

napi_value mtraceWrapper(napi_env env, napi_callback_info args) {
   napi_value result;
  napi_status status;
	mtrace();
  status = napi_create_uint32(env,1,&result);
  if (status != napi_ok) return nullptr;
  return result;
  }

napi_value muntraceWrapper(napi_env env, napi_callback_info args) {
  napi_value result;
  napi_status status;
	muntrace();
  status = napi_create_uint32(env,1,&result);
  if (status != napi_ok) return nullptr;
  return result;
}

napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn1;
  napi_value fn2;

  status = napi_create_function(env, nullptr, 0, mtraceWrapper, nullptr, &fn1);
  if (status != napi_ok) return nullptr;
  status = napi_set_named_property(env, exports, "mtrace", fn1);
  if (status != napi_ok) return nullptr;

  status = napi_create_function(env, nullptr, 0, muntraceWrapper, nullptr, &fn2);
  if (status != napi_ok) return nullptr;
  status = napi_set_named_property(env, exports, "muntrace", fn2);
  if (status != napi_ok) return nullptr;
  
  return exports;
}

NAPI_MODULE(mtrace, init)

