In file included from /usr/include/c++/4.9.2/string:48:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_function.h: In instantiation of ‘bool std::less<_Tp>::operator()(const _Tp&, const _Tp&) const [with _Tp = Pair]’:
/usr/include/c++/4.9.2/bits/stl_map.h:498:31:   required from ‘std::map<_Key, _Tp, _Compare, _Alloc>::mapped_type& std::map<_Key, _Tp, _Compare, _Alloc>::operator[](const key_type&) [with _Key = Pair; _Tp = int; _Compare = std::less<Pair>; _Alloc = std::allocator<std::pair<const Pair, int> >; std::map<_Key, _Tp, _Compare, _Alloc>::mapped_type = int; std::map<_Key, _Tp, _Compare, _Alloc>::key_type = Pair]’
main.cpp:62:30:   required from here
/usr/include/c++/4.9.2/bits/stl_function.h:371:20: error: no match for ‘operator<’ (operand types are ‘const Pair’ and ‘const Pair’)
       { return __x < __y; }
                    ^
/usr/include/c++/4.9.2/bits/stl_function.h:371:20: note: candidates are:
In file included from /usr/include/c++/4.9.2/bits/stl_algobase.h:64:0,
                 from /usr/include/c++/4.9.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.9.2/ios:40,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_pair.h:220:5: note: template<class _T1, class _T2> bool std::operator<(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)
     operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
     ^
/usr/include/c++/4.9.2/bits/stl_pair.h:220:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/4.9.2/string:48:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_function.h:371:20: note:   ‘const Pair’ is not derived from ‘const std::pair<_T1, _T2>’
       { return __x < __y; }
                    ^
In file included from /usr/include/c++/4.9.2/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/4.9.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.9.2/ios:40,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_iterator.h:298:5: note: template<class _Iterator> bool std::operator<(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)
     operator<(const reverse_iterator<_Iterator>& __x,
     ^
/usr/include/c++/4.9.2/bits/stl_iterator.h:298:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/4.9.2/string:48:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_function.h:371:20: note:   ‘const Pair’ is not derived from ‘const std::reverse_iterator<_Iterator>’
       { return __x < __y; }
                    ^
In file included from /usr/include/c++/4.9.2/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/4.9.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.9.2/ios:40,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_iterator.h:348:5: note: template<class _IteratorL, class _IteratorR> bool std::operator<(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_IteratorR>&)
     operator<(const reverse_iterator<_IteratorL>& __x,
     ^
/usr/include/c++/4.9.2/bits/stl_iterator.h:348:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/4.9.2/string:48:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_function.h:371:20: note:   ‘const Pair’ is not derived from ‘const std::reverse_iterator<_Iterator>’
       { return __x < __y; }
                    ^
In file included from /usr/include/c++/4.9.2/string:52:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/basic_string.h:2588:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator<(const std::basic_string<_CharT, _Traits, _Alloc>&, const std::basic_string<_CharT, _Traits, _Alloc>&)
     operator<(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^
/usr/include/c++/4.9.2/bits/basic_string.h:2588:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/4.9.2/string:48:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_function.h:371:20: note:   ‘const Pair’ is not derived from ‘const std::basic_string<_CharT, _Traits, _Alloc>’
       { return __x < __y; }
                    ^
In file included from /usr/include/c++/4.9.2/string:52:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/basic_string.h:2600:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator<(const std::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*)
     operator<(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^
/usr/include/c++/4.9.2/bits/basic_string.h:2600:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/4.9.2/string:48:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_function.h:371:20: note:   ‘const Pair’ is not derived from ‘const std::basic_string<_CharT, _Traits, _Alloc>’
       { return __x < __y; }
                    ^
In file included from /usr/include/c++/4.9.2/string:52:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/basic_string.h:2612:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator<(const _CharT*, const std::basic_string<_CharT, _Traits, _Alloc>&)
     operator<(const _CharT* __lhs,
     ^
/usr/include/c++/4.9.2/bits/basic_string.h:2612:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/4.9.2/string:48:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_function.h:371:20: note:   mismatched types ‘const _CharT*’ and ‘Pair’
       { return __x < __y; }
                    ^
In file included from /usr/include/c++/4.9.2/map:60:0,
                 from main.cpp:6:
/usr/include/c++/4.9.2/bits/stl_tree.h:980:5: note: template<class _Key, class _Val, class _KeyOfValue, class _Compare, class _Alloc> bool std::operator<(const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>&, const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>&)
     operator<(const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& __x,
     ^
/usr/include/c++/4.9.2/bits/stl_tree.h:980:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/4.9.2/string:48:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_function.h:371:20: note:   ‘const Pair’ is not derived from ‘const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>’
       { return __x < __y; }
                    ^
In file included from /usr/include/c++/4.9.2/map:61:0,
                 from main.cpp:6:
/usr/include/c++/4.9.2/bits/stl_map.h:1017:5: note: template<class _Key, class _Tp, class _Compare, class _Alloc> bool std::operator<(const std::map<_Key, _Tp, _Compare, _Alloc>&, const std::map<_Key, _Tp, _Compare, _Alloc>&)
     operator<(const map<_Key, _Tp, _Compare, _Alloc>& __x,
     ^
/usr/include/c++/4.9.2/bits/stl_map.h:1017:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/4.9.2/string:48:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_function.h:371:20: note:   ‘const Pair’ is not derived from ‘const std::map<_Key, _Tp, _Compare, _Alloc>’
       { return __x < __y; }
                    ^
In file included from /usr/include/c++/4.9.2/map:62:0,
                 from main.cpp:6:
/usr/include/c++/4.9.2/bits/stl_multimap.h:920:5: note: template<class _Key, class _Tp, class _Compare, class _Alloc> bool std::operator<(const std::multimap<_Key, _Tp, _Compare, _Alloc>&, const std::multimap<_Key, _Tp, _Compare, _Alloc>&)
     operator<(const multimap<_Key, _Tp, _Compare, _Alloc>& __x,
     ^
/usr/include/c++/4.9.2/bits/stl_multimap.h:920:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/4.9.2/string:48:0,
                 from /usr/include/c++/4.9.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.9.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.9.2/ios:42,
                 from /usr/include/c++/4.9.2/ostream:38,
                 from /usr/include/c++/4.9.2/iostream:39,
                 from main.cpp:1:
/usr/include/c++/4.9.2/bits/stl_function.h:371:20: note:   ‘const Pair’ is not derived from ‘const std::multimap<_Key, _Tp, _Compare, _Alloc>’
       { return __x < __y; }
                    ^
