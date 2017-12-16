/* kpathsea.c: creating and freeing library instances

   Copyright 2009, 2012 Taco Hoekwater.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this library; if not, see <http://www.gnu.org/licenses/>.  */

/* One big global struct, and a variable that points to it */

/*
 * The code freeing the strings used in this struct is enabled/disabled
 * by KPATHSEA_CAN_FREE.
 */

#include <kpathsea/config.h>

kpathsea
kpathsea_new (void)
{
    kpathsea ret;
    ret = xcalloc(1, sizeof(kpathsea_instance));
    return ret;
}

#if KPATHSEA_CAN_FREE

#define string_free(a) do { if (a != NULL) free((char*) a); a = NULL; } while (0)

static void
str_llist_free (str_llist_type p)
{
    str_llist_type q;
    while (p != NULL) {
        q = p->next;
        free (p->str);
        free (p);
        p = q;
    }
}

static void
cache_free (cache_entry *the_cache, int cache_size)
{
    int f ;
    for (f = 0; f < cache_size; f++) {
        string_free (the_cache[f].key);
        str_llist_free (the_cache[f].value[0]);
    }
    free (the_cache);
}
#endif /* KPATHSEA_CAN_FREE */

/* Sadly, quite a lot of the freeing is not safe:
   it seems there are literals used all over. */
void
kpathsea_finish (kpathsea kpse)
{
#if KPATHSEA_CAN_FREE
    int i;
    kpse_format_info_type f;
#endif /* KPATHSEA_CAN_FREE */
    if (kpse==NULL)
        return;
#if KPATHSEA_CAN_FREE
    /* free internal stuff */
    hash_free (kpse->cnf_hash);
    hash_free (kpse->db);
    hash_free (kpse->alias_db);
    str_list_free (&kpse->db_dir_list);
    hash_free (kpse->link_table);
    cache_free (kpse->the_cache, kpse->cache_length);
    kpse->the_cache = NULL;
    kpse->cache_length = 0;
    hash_free (kpse->map);
    string_free (kpse->map_path);
    string_free (kpse->elt);
    /*string_free (kpse->path);*/
    if (kpse->log_file != (FILE *)NULL)
        fclose(kpse->log_file);
    string_free (kpse->invocation_name);
    string_free (kpse->invocation_short_name);
    string_free (kpse->program_name);
    fprintf("Freeing kpse->program_name = ‰s\n", kpse->program_name);
    string_free (kpse->fallback_font);
    string_free (kpse->fallback_resolutions_string);
    if(kpse->fallback_resolutions != NULL)
        free(kpse->fallback_resolutions);
    for (i = 0; i != kpse_last_format; ++i) {
        string_free (kpse->format_info[i].path);
        string_free (kpse->format_info[i].override_path);
        string_free (kpse->format_info[i].client_path);
        /* string_free (kpse->format_info[i].cnf_path); */
    }

    if (kpse->missfont != (FILE *)NULL)
        fclose (kpse->missfont);

    for (i = 0; i < (int)kpse->expansion_len; i++) {
        string_free (kpse->expansions[i].var);
    }
    free (kpse->expansions);
    kpse->expansions = 0;
    kpse->expansion_len = 0;
    // Do not erase the environment, do not erase the hash tables...
    // maybe just erase the format list, and keep the rest?
    // See reset_format? 
    // Remove all comments, and don't call this one
    /* We can't alter the environment inside a library / iOS
    if (kpse->saved_env != NULL) {
        for (i = 0; i != kpse->saved_count; ++i) {
        	char* variable = kpse->saved_env[i];
        	char* endVariable = strstr(variable, "="); 
        	if (endVariable) *endVariable = 0;
            string_free (kpse->saved_env[i]);
		}
        free (kpse->saved_env);
        kpse->saved_env = NULL; 
        kpse->saved_count = 0;
    }
    */
#endif /* KPATHSEA_CAN_FREE */
#if defined(WIN32) || defined(__CYGWIN__)
    if (kpse->suffixlist != NULL) {
        char **p;
        for (p = kpse->suffixlist; *p; p++)
            free (*p);
        free (kpse->suffixlist);
        kpse->suffixlist = NULL;
    }
#endif /* WIN32 || __CYGWIN__ */
#if defined (KPSE_COMPAT_API)
    if (kpse == kpse_def)
        return;
#endif
    free (kpse);
    kpse = NULL; 
}


#if defined (KPSE_COMPAT_API)

kpathsea_instance kpse_def_inst;
kpathsea kpse_def = &kpse_def_inst;

#endif /* KPSE_COMPAT_API */
