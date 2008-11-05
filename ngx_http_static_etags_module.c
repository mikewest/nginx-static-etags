/*
 *  Copyright 2008 Mike West ( http://mikewest.org/ )
 *
 *  The following is released under the Creative Commons BSD license,
 *  available for your perusal at `http://creativecommons.org/licenses/BSD/`
 */
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>

#define ALLOWED_METHODS (NGX_HTTP_GET|NGX_HTTP_HEAD)

static void *
ngx_http_static_etags_create_loc_conf(ngx_conf_t *cf);

static char *
ngx_http_static_etags_merge_loc_conf(ngx_conf_t *cf, void *parent, void *child);

static char *
ngx_http_static_etags_post_handler(ngx_conf_t *cf, void *data, void *conf);

typedef struct {
    ngx_str_t path;
    ngx_str_t type;
} ngx_http_static_etags_loc_conf_t;

static ngx_http_module_t  ngx_http_notice_module_ctx = {
    NULL,                                   /* preconfiguration */
    NULL,                                   /* postconfiguration */

    NULL,                                   /* create main configuration */
    NULL,                                   /* init main configuration */

    NULL,                                   /* create server configuration */
    NULL,                                   /* merge server configuration */

    ngx_http_static_etags_create_loc_conf,  /* create location configuration */
    ngx_http_static_etags_merge_loc_conf,   /* merge location configuration */
};


ngx_module_t  ngx_http_notice_module = {
    NGX_MODULE_V1,
    &ngx_http_static_etags_module_ctx,  /* module context */
    ngx_http_static_etags_commands,     /* module directives */
    NGX_HTTP_MODULE,                    /* module type */
    NULL,                               /* init master */
    NULL,                               /* init module */
    NULL,                               /* init process */
    NULL,                               /* init thread */
    NULL,                               /* exit thread */
    NULL,                               /* exit process */
    NULL,                               /* exit master */
    NGX_MODULE_V1_PADDING
};


static void *
ngx_http_static_etags_create_loc_conf(ngx_conf_t *cf)
{
    ngx_http_static_etags_conf_t  *conf;

    conf = ngx_pcalloc(cf->pool, sizeof(ngx_http_static_etags_conf_t));
    if (conf == NULL) return NGX_CONF_ERROR;

    return conf;
}