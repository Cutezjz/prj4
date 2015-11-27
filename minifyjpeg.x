/*
 * Complete this file and run rpcgen -MN minifyjpeg.x
 */
struct minify_out {
 	opaque src<>;
};

program MINIFY_PROG{
	version MINIFY_VERS{
		minify_out MINIFY_PROC(minify_out) = 1;
	} = 1;
} = 0x31230000;