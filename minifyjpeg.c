#include "minifyjpeg.h"
#include "magickminify.h"

/* Implement the needed server-side functions here */
minify_out * minify_proc_1_svc(minify_out in, struct svc_req *req)
{
	minify_out *out = (minify_out *)malloc(sizeof(minify_out));
	size_t src_len;
	magickminify_init();
	out->src.src_val = magickminify(in.src.src_val, in.src.src_len, &src_len);
	out->src.src_len = src_len;
	printf("out->src.src_len = ", out->src.src_len);
	//out->src_len = in.src_len;
	magickminify_cleanup();
	return out;
}


int minify_prog_1_freeresult (SVCXPRT *a, xdrproc_t b, caddr_t c)
{
	return 0;
}
