void	print_circle(int c_x, int c_y, int rad)
{
    int	x;
    int y;

    x = rad;
    y = rad;
    while((x * x) + (y * y) >= (rad * rad))
    {
        while ((x * x) + (y * y) >= (rad * rad))
        {
            if ( (x * x) + (y * y) == (rad * rad))
            {
                my_mlx_pixel_put(&img, c_x + x, c_y + y, 0xFF0000);
                my_mlx_pixel_put(&img, c_x - x, c_y - y, 0xFF0000);
            }
            x--;
        }
        x = rad;
        y--;
    }

}

void print_img_info(t_data *img)
{
    printf("%p\n", img->img);
    printf("%d\n", img->bits_per_pixel);
    printf("%d\n", img->line_length);
    printf("%d\n", img->endian);
}