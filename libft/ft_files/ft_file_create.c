#include "libft.h"

static inline char	*ft_string_concat(char *str1, char *str2)
{
	char			*ret;
	size_t			len;
	size_t			i;
	size_t			len_1;
	size_t			len_2;

	i = -1;
	len = 0;
	len_1 = ft_strlen(str1);
	len_2 = ft_strlen(str2);
	len = len_1 + len_2;
	ret = (char *)ft_malloc(sizeof(char) * len);
	while (++i < len_1)
		ret[i] = str1[i];
	i = -1;
	while (++i < len_2)
		ret[len_1 + i] = str2[i];
	return (ret);
}

int					ft_files_create(char *path, char *filename,
			char *filecontent)
{
	struct dirent	*files;
	int				fd;
	DIR				*dir;
	char			*concat;

	fd = 0;
	if (!filename || !path)
		return (1);
	dir = opendir(path);
	if (!dir)
		return (2);
	while ((files = readdir(dir)) != NULL)
	{
		if (ft_strcmp(files->d_name, filename) == 0)
			return (3);
	}
	concat = ft_string_concat(path, filename);
	fd = open(concat, O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if (filecontent)
		write(fd, filecontent, ft_strlen(filecontent));
	close(fd);
	ft_strdel(&concat);
	free(files);
	closedir(dir);
	return (0);
}
