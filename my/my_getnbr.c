/*
** my_getnbr.c for philo1 in /home/hochwe_f/afs/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 20:21:56 2008 florent hochwelker
** Last update Sun May 11 18:48:14 2008 florent hochwelker
*/

int	my_getnbr(char *str)
{
  int	result;

  result = 0;
  while (*str && *str >= '0' && *str <= '9')
    {
      result *= 10;
      result += *str - '0';
      str++;
    }
  return (result);
}
