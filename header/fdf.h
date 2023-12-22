#ifndef FDF_H
# define FDF_H

typedef struct s_data {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_len;
	int endian;
}								t_data;

typedef struct s_trgb {
	int t;
	int r;
	int g;
	int b;
}								t_trgb;

typedef struct s_vars {
	void *mlx;
	void *win;
}								t_vars;

int create_trgb(t_trgb *t_trgb);
int add_shade(t_trgb *t_trgb, double shade_factor);
int get_opposite(t_trgb *t_trgb);

#endif
