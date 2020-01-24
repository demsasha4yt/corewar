void check_name_comment_name_p2(i, asm_ms)
{
	int j;
	char *str;

	while (get_next_line(asm_ms->fd_r, &str))
	{
		asm_ms->name[i++] = '\n';
		j = 0;
		while (str[j] != '"' && str[j] && i < 128)
		{
			asm_ms->name[i] = str[j];
			j++;
		}
		if (i == 128)
			ft_printf("error number symbols (name)\n");
		if (str[j] == '"')
		{
			//проверка на валидность строки после ковычки
			return ;
		}
		free(str);
	}
}
