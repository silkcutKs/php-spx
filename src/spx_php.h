#ifndef SPX_PHP_H_DEFINED
#define SPX_PHP_H_DEFINED

typedef struct {
    unsigned long hash_code;
    
    const char * file_name;
    int line;

    const char * func_name;
    const char * call_type;
    const char * class_name;
} spx_php_function_t;

int spx_php_is_cli_sapi(void);

void spx_php_current_function(spx_php_function_t * function);

const char * spx_php_global_array_get(const char * name, const char * key);
char * spx_php_build_command_line(void);

size_t spx_php_zend_memory_usage(void);
size_t spx_php_zend_root_buffer_length(void);
size_t spx_php_zend_object_count(void);
size_t spx_php_zend_error_count(void);

void spx_php_hooks_init(void);
void spx_php_hooks_shutdown(void);

void spx_php_execution_init(void);
void spx_php_execution_shutdown(void);
void spx_php_execution_disable(void);
void spx_php_execution_hook(void (*before)(void), void (*after)(void), int internal);

void spx_php_execution_output_disable(void);
void spx_php_execution_output_restore(void);

size_t spx_php_output_direct_write(const void * ptr, size_t len);
size_t spx_php_output_direct_print(const char * str);
int spx_php_output_direct_printf(const char * fmt, ...);

void spx_php_ouput_finalize(void);

#endif /* SPX_PHP_H_DEFINED */
