#ifndef X_PRINT_FORMAT_H_
# define X_PRINT_FORMAT_H_

# define X_PRINT_FORMAT_(type)	X_PRINT_FORMAT_##type
# define X_PRINT_FORMAT_int	"%d"
# define X_PRINT_FORMAT_double	"%lf"
# define X_PRINT_FORMAT_float	"%f"
# define X_PRINT_FORMAT_long	"%ld"
# define X_PRINT_FORMAT_char	"%c"

#endif	/* !X_PRINT_FORMAT_H_ */
