#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include <mosquitto_broker.h>
#include <mosquitto_plugin.h>
#include <mosquitto.h>


#if MOSQ_AUTH_PLUGIN_VERSION >= 3
# define mosquitto_auth_opt mosquitto_opt
#endif


int mosquitto_auth_plugin_version(void) {
  #ifdef MOSQ_AUTH_PLUGIN_VERSION
    #if MOSQ_AUTH_PLUGIN_VERSION == 5
      return 4; // This is v2.0, use the backwards compatibility
    #else
      return MOSQ_AUTH_PLUGIN_VERSION;
    #endif
  #else
    return 4;
  #endif
}

int mosquitto_auth_plugin_init(void **user_data, struct mosquitto_auth_opt *auth_opts, int auth_opt_count) {
  return MOSQ_ERR_SUCCESS;
}

int mosquitto_auth_plugin_cleanup(void *user_data, struct mosquitto_auth_opt *auth_opts, int auth_opt_count) {

  return MOSQ_ERR_SUCCESS;
}

int mosquitto_auth_security_init(void *user_data, struct mosquitto_auth_opt *auth_opts, int auth_opt_count, bool reload) {
  return MOSQ_ERR_SUCCESS;
}

int mosquitto_auth_security_cleanup(void *user_data, struct mosquitto_auth_opt *auth_opts, int auth_opt_count, bool reload) {
  return MOSQ_ERR_SUCCESS;
}

// #if MOSQ_AUTH_PLUGIN_VERSION >= 4
// int mosquitto_auth_unpwd_check(void *user_data, struct mosquitto *client, const char *username, const char *password)
// #elif MOSQ_AUTH_PLUGIN_VERSION >=3
// int mosquitto_auth_unpwd_check(void *userdata, const struct mosquitto *client, const char *username, const char *password)
// #else
// int mosquitto_auth_unpwd_check(void *userdata, const char *username, const char *password)
// #endif
// {
//   #if MOSQ_AUTH_PLUGIN_VERSION >= 3
//     const char* clientid = mosquitto_client_id(client);
//   #else
//     const char* clientid = "";
//   #endif
//   if (username == NULL || password == NULL) {
//     printf("error: received null username or password for unpwd check\n");
//     fflush(stdout);
//     return MOSQ_ERR_AUTH;
//   }

//   printf("====================================================\n");
//   printf(username);
//   printf("\n====================================================\n");



//     return MOSQ_ERR_SUCCESS;
//     // return MOSQ_ERR_AUTH;
//     // return MOSQ_ERR_UNKNOWN;
// }

#if MOSQ_AUTH_PLUGIN_VERSION >= 4
int mosquitto_auth_acl_check(void *user_data, int access, struct mosquitto *client, const struct mosquitto_acl_msg *msg)
#elif MOSQ_AUTH_PLUGIN_VERSION >= 3
int mosquitto_auth_acl_check(void *userdata, int access, const struct mosquitto *client, const struct mosquitto_acl_msg *msg)
#else
int mosquitto_auth_acl_check(void *userdata, const char *clientid, const char *username, const char *topic, int access)
#endif
{
  #if MOSQ_AUTH_PLUGIN_VERSION >= 3
    const char* clientid = mosquitto_client_id(client);
    const char* username = mosquitto_client_username(client);
    const char* topic = msg->topic;
  #endif
  if (clientid == NULL || username == NULL || topic == NULL || access < 1) {
    printf("error: received null username, clientid or topic, or access is equal or less than 0 for acl check\n");
    fflush(stdout);
    return MOSQ_ERR_ACL_DENIED;
  }

  printf("====================================================\n");
  printf(topic);
  printf(" - ");
  printf(msg->payload);

  printf("\n====================================================\n");
  


    return MOSQ_ERR_SUCCESS;
    // return MOSQ_ERR_ACL_DENIED;
    // return MOSQ_ERR_UNKNOWN;
}

#if MOSQ_AUTH_PLUGIN_VERSION >= 4
int mosquitto_auth_psk_key_get(void *user_data, struct mosquitto *client, const char *hint, const char *identity, char *key, int max_key_len)
#elif MOSQ_AUTH_PLUGIN_VERSION >= 3
int mosquitto_auth_psk_key_get(void *userdata, const struct mosquitto *client, const char *hint, const char *identity, char *key, int max_key_len)
#else
int mosquitto_auth_psk_key_get(void *userdata, const char *hint, const char *identity, char *key, int max_key_len)
#endif
{
  return MOSQ_ERR_AUTH;
}

