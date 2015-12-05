int	is_alnum(int c)
{
  if (is_alpha(c) || is_digit(c))
    return (1);
  return (0);
}

int	is_alpha(int c)
{
  if (is_upper(c) || is_lower(c))
    return (1);
  return (0);
}

int	is_ascii(int c)
{
  if (c >= 0 && c < 128)
    return (1);
  return (0);
}

int	is_blank(int c)
{
  if (c == ' ' || c == '\t')
    return (1);
  return (0);
}

int	is_cntrl(int c)
{
  if (c == '\033')
    return (1);
  return (0);
}

int	is_digit(int c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	is_graph(int c)
{
  if (is_print(c) && c != ' ')
    return (1);
  return (0);
}

int	is_lower(int c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

int	is_print(int c)
{
  if (c > 31 && c < 127)
    return (1);
  return (0);
}

int	is_punct(int c)
{
  if (is_graph(c) && !is_alnum(c))
    return (1);
  return (0);
}

int	is_space(int c)
{
  if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
    return (1);
  return (0);
}

int	is_upper(int c)
{
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

int	is_xdigit(int c)
{
  if (is_digit(c) || (c >= 'A' && c <= 'F'))
    return (1);
  return (0);
}
