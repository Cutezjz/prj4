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


	minify_in in = {.src = src_val, .src_len = src_len};
	minify_in out = {.src = NULL, .src_len = 0};
	char * dst_src = (char *)malloc(sizeof(char) * in.src_len);
	minify_proc_1(in, &out, cl);
	memcpy(dst_src, out.src, out.src_len);
	return dst_src;
    

}
