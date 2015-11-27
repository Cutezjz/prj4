#include <stdlib.h>
#include <stdio.h>
#include "minifyjpeg_xdr.c"
#include "minifyjpeg_clnt.c"

CLIENT* get_minify_client(char *server){
    CLIENT *cl;

    /* Your code here */
    cl = clnt_create(server, MINIFY_PROG, MINIFY_VERS, "tcp");
    if (cl == NULL)
    {
    	//clnt_pcreaterror(server);
    	perror("clnt_create");
    }

    return cl;
}


void* minify_via_rpc(CLIENT *cl, void* src_val, size_t src_len, size_t *dst_len){

	/*Your code here */


	minify_out in;
	minify_out *outp = NULL;
	in.src.src_len = src_len;
	in.src.src_val = src_val;

	outp = minify_proc_1(in, cl);
	char * dst_src = (char *)malloc(sizeof(char) * outp->src.src_len);
	memcpy(dst_src, outp->src.src_val, outp->src.src_len);
	*dst_len = outp->src.src_len;
	return dst_src;
}

