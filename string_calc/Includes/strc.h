void 	strgrow(char *src);
int 	max(int a, int b);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*str_alloc(int size, char c);
char	*ft_strjoin(char *s1, char *s2);
char 	*ft_strjoin_free(char *out, char *add);

typedef struct {
	char 	*str;
	int 	size;
} t_str_nb;


char	*print_bin(unsigned char nb, int iter);
int		print_bits(long double *nb);
