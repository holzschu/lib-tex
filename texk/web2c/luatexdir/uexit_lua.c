/* uexit.c: define uexit to do an exit with the right status.  We can't
   just call `exit' from the web files, since the webs use `exit' as a
   loop label.  Public domain. */
// uexit_lua: called only from luatex. Releases all memory allocated, sets variables to 0, etc. 

#include <w2c/config.h>
#ifdef __IPHONE__
#include <pthread.h>
#include "ptexlib.h"
extern string input_name;
extern void clear_string_pool();
extern void clear_node_mem();
extern void clear_font_data();
extern void clear_math_data(); 
extern void clear_tex_languages(); 
extern void* mitem; 
extern void* jump_table; 
extern int lua_offset;
#endif

void
uexit_lua (int unix_code)
{
	int final_code;

	if (unix_code == 0)
		final_code = EXIT_SUCCESS;
	else if (unix_code == 1)
		final_code = EXIT_FAILURE;
	else
		final_code = unix_code;
#ifdef __IPHONE__
	// This function is called for each exit, either regular exit 
	// or exit after error. 
	// We need to deallocate everything
	// Allocated in luainit.c
	if (output_comment != NULL) xfree(output_comment); 
	if (startup_filename != NULL) xfree(startup_filename); 
	if (luatex_banner != NULL) xfree(luatex_banner);
	lua_only = 0;
	lua_offset = 0;
	show_luahashchars = 0;
#ifdef LuajitTeX
	luajiton   = 0;
	xfree(*jithash_hashname);
#endif
	safer_option = 0;
	nosocket_option = 0;
	utc_option = 0;
	// 
	// Set in texfileio.w
	job_name = 0; 
	log_opened_global = false;
	name_in_progress = false; 
	// Set in printing.w
	selector = term_only;           /* where to print a message */
    tally = 0;                      /* the number of characters recently printed */
    term_offset = 0;                /* the number of characters on the current terminal line */
    file_offset = 0;                /* the number of characters on the current file line */
	inhibit_par_tokens = false; /*  for minor adjustments to |show_token_list|  */
	// Allocated in font/mapfile.w
	xfree(mitem); 
	// Allocated in maincontrol.w
	xfree(jump_table); 
	font_bytes = 0; 
	// Allocated/set in mainbody.w:
	xfree(buffer);
	xfree(nest);
	xfree(save_stack); 
	xfree(input_stack);
	xfree(input_file);
	xfree(input_file_callback_id); 
	xfree(line_stack);
	xfree(eof_seen);
	xfree(grp_stack);
	xfree(if_stack);
	xfree(source_filename_stack);
	xfree(full_source_filename_stack); 
	xfree(param_stack);
	xfree(dvi_buf);
	xfree(fixmem); 
	fix_mem_min = 0; 
	fix_mem_max = 0; 
	xfree(hash); 
	hash_used = 0;
	hash_top = 0;
	hash_high = 0;
	xfree(eqtb); 
	eqtb_top = 0;
	reset_cur_string();
	cur_chr = 0;
	cur_cs = 0;
	cur_tok = 0; 
	last_cs_name = 0;
	biggest_used_mark = 0;
	write_loc = 0; 
	pseudo_files = 0;
	just_box = 0;
	last_line_fill = 0;
	ini_version = false;            /* are we \.{INITEX}? */
	dump_option = false;            /* was the dump name option used? */
	dump_line = false;              /* was a \.{\%\AM format} line seen? */
	quoted_filename = false;        /* current filename is quoted */
	
	bound_default = 0;              /* temporary for setup */
	error_line = 0;                 /* width of context lines on terminal error messages */
	half_error_line = 0;            /* width of first lines of contexts in terminal
									   error messages = 0; should be between 30 and |error_line-15| */
	max_print_line = 0;             /* width of longest text lines output; should be at least 60 */
	max_strings = 0;                /* maximum number of strings; must not exceed |max_halfword| */
	strings_free = 0;               /* strings available after format loaded */
	font_k = 0;                     /* loop variable for initialization */
	buf_size = 0;                   /* maximum number of characters simultaneously present in
									   current lines of open files and in control sequences between
									   \.{\\csname} and \.{\\endcsname} = 0; must not exceed |max_halfword| */
	stack_size = 0;                 /* maximum number of simultaneous input sources */
	max_in_open = 0;                /* maximum number of input files and error insertions that
									   can be going on simultaneously */
	param_size = 0;                 /* maximum number of simultaneous macro parameters */
	nest_size = 0;                  /* maximum number of semantic levels simultaneously active */
	save_size = 0;                  /* space for saving values outside of current group; must be
									   at most |max_halfword| */
	expand_depth = 0;               /* limits recursive calls of the |expand| procedure */
	parsefirstlinep = 0;            /* parse the first line for options */
	filelineerrorstylep = 0;        /* format messages as file:line:error */
	haltonerrorp = 0;               /* stop at first error */
	// utils.w
	make_subset_tag(NULL); // Clears st_stree
	// set in inputstack.w:
	input_ptr = 0; 
	max_in_stack = 0; 
	in_open = 0; 
	open_parens = 0; 
	scanner_status = 0; 
	warning_index = null; 
	def_ref = null; 
	param_ptr = 0; 
	max_param_stack = 0; 
	align_state = 0; 
	base_ptr = 0; 
	// set in pdfgen.w:
    pdf_info_toks = 0;                              /* additional keys of Info dictionary */
    pdf_catalog_toks = 0;                           /* additional keys of Catalog dictionary */
    pdf_catalog_openaction = 0;
    pdf_names_toks = 0;                             /* additional keys of Names dictionary */
    pdf_trailer_toks = 0;                           /* additional keys of Trailer dictionary */
    xfree(static_pdf); 
    static_pdf = NULL; 
    global_shipping_mode = NOT_SHIPPING; /* set to |shipping_mode| when |ship_out| starts */
    // 
    // buildpage.h
    // TODO: check the initial value for all these.
    page_tail = 0;
    best_page_break = 0;
    last_glue = 0; 
	cond_ptr = 0; 
	dir_ptr = 0;
	text_dir_ptr = 0;
	// Clearing databases:
	clear_font_data();
	clear_string_pool(); 
	clear_node_mem(); // frees varmem
	var_mem_max = 0;
	attr_list_cache = 0;
	clear_math_data();
	clear_tex_languages();
	// lua_close was called in luatexdir/tex/errors.w
	if (Luas != NULL) {
		lua_close(Luas); Luas = NULL;
	}
	luastate_bytes = 0; 
	lua_active = 0; 
	// All variables in luainit.w
	kpse_init = -1; 
	xfree(input_name);
	dump_name = NULL; // dump_name needs to be reset, but not freed
	// it's a pointer to an area that has already been freed. 
	// dvigen.h
	down_ptr = 0;
	right_ptr = 0;
	total_pages = 0; 
	// writeimg.h
	idict_ptr = NULL; 
	xfree(idict_array);
	idict_array = NULL;
	cur_box = 0;
	after_token = 0;
	save_tail = 0;
	adjust_tail = 0;
	pre_adjust_tail = 0;
	last_leftmost_char = 0;
	last_rightmost_char = 0;
	next_char_p = 0;
	prev_char_p = 0;
	garbage = 0;
	temp_token_head = 0;
	hold_token_head = 0;
	omit_template = 0;
	backup_head = 0;
	avail = 0;
	par_loc = 0;
	par_token = 0;
	pthread_exit(NULL); 
#else 
	exit (final_code);
#endif 
}
