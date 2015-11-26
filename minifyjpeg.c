#include "minifyjpeg.h"
#include "magickminify.h"

/* Implement the needed server-side functions here */

bool_t minify_proc_1_svc(minify_in in, minify_in * out, struct svc_req * req)
{

	puts("minify_proc_1_svc");
	puts("steww");
	printf("out.src_len = %d\n", out->src_len);
	magickminify_init();
	puts("post init");
	out->src = magickminify((void *)in.src, in.src_len, &out->src_len);
	puts("post magickmnify");
	printf("out.src_len = ", out->src_len);
	//out->src_len = in.src_len;
	magickminify_cleanup();
}

int minify_prog_1_freeresult (SVCXPRT *a, xdrproc_t b, caddr_t c)
{
	return 0;
}
