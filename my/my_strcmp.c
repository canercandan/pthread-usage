/*
** my_strcmp.c for my_strcmp in /u/epitech_2010s/hochwe_f/cu/rendu/piscine/Jour_06
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Mon Oct  8 20:49:29 2007 florent hochwelker
** Last update Sat May 10 12:53:34 2008 florent hochwelker
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    if (s1[i] == s2[i])
      i++;
    else
      return ((s1[i] - s2[i]));
  return (0);
}
