//
// Created by Drien BRETON on 1/3/17.
//

int 		tab_len(char **tab)
{
	int		i = 0;

	while (tab[i])
		++i;
	return (i);
}