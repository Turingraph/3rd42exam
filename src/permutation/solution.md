Things to consider
1.  You have to have the heap for marking which char is already taking in the previous stack
2.  get_ith_char return the index-th available character (with the helps of is_a_in_str(str[i ], mark)).
3.  set and reset like this.

```
current_note = get_ith_char(mark, str, i);
mark[index] = str[current_note];
write_permutations(str, mark, index + 1, length);
mark[index] = '\0';
```

4.  Loop only length - index times, because when you enter the index-th depth recursion, you always have length - index availables option from str (string input) left.
