/*
 * Complete this file and run rpcgen -MN minifyjpeg.x
 */
struct minify_in {
 	string src<>;
 	long src_len;
};

program MINIFY_PROG{
	version MINIFY_VERS{
		minify_in MINIFY_PROC(minify_in) = 1;
	} = 1;
} = 0x31230000;