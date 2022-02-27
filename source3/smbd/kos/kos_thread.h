#ifndef KOS_THREAD
#define KOS_THREAD

#define KOS_NO_FORK

#ifdef KOS_NO_FORK

struct kos_conn_data {
    struct dcesrv_context *dce_ctx;
    int fd;
};

int kos_run_conn(struct kos_conn_data data);

#endif

#endif