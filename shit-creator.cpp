#include <bits/stdc++.h>
using namespace std;

inline bool ok(char ch) {
	if ('a' <= ch && ch <= 'z') return 1;
	if ('A' <= ch && ch <= 'Z') return 1;
	if (isdigit(ch)) return 1;
	if (ch == '_') return 1;
	if (ch == '$') return 1;
	return 0;
}

set<string> keys;
inline bool key(string s) {
	return keys.find(s) != keys.end();
}

inline void init() {
    string ks[1001] = {
        "int", "vector", "map", "bits", "include", "stdc", "using", "namespace", "std", "bool", 
        "inline", "register", "unsigned", "char", "getchar", "isdigit", "return",
        "main", "scanf", "printf", "do", "if", "string", "set", "find", "end", "define", "mt19937", "switch", "case",
        "for", "insert", "while", "EOF", "class", "private", "public", "protected", "size", "length", "true", "false",
        "continue", "break", "cin", "cout", "endl", "else", "struct", "enum", "begin", "const", "ifdef", "ifndef", "long", "new",
        "signed", "void", "uniform_int_distribution", "fread", "fwrite", "FILE", "static", "typedef", "first", "second", "pair",
        "push_back", "emplace_back", "push", "pop", "pop_back", "sort", "unique", "resize", "stack", "top", "lower_bound", "empty", "back",
        "swap", "freopen", "fclose", "stdin", "stdout", "make_pair", "auto",
        "bitset", "hash", "operator", "template", "typename", "noexcept", "default", "constexpr", "explicit", "reset", "flip", "test", "any", "all", "none", "count", "to_string",
        "to_ulong", "to_ullong", "float", "double", "char16_t", "char32_t", "wchar_t", "short", "function", "bind", "ref", "cref", "invoke",
        "assign", "CLOCKS_PER_SEC", "clock", "NULL", "nullptr", "time", "clock_t", "size_t", "time_t", "tm", "__VA_ARGS__", 
        "initializer_list", "tuple", "make_tuple", "tie", "get", "tuple_cat",
        "max", "min", "clear", "greater", "less", "plus", "friend", "this", "puts", "memset", "sizeof", "boolalpha", "volatile",
        "goto", "__gcd", "__builtin_popcount", "__builtin_ctz", "__builtin_clz", "__builtin_ffs", "fill_n",
        "strlen", "strcat", "strcpy", "memcpy", "memmove", "shuffle", "random_shuffle",
        "isupper", "islower", "isalnum", "isalpha", "rand", "strcmp", "compare",
        "push_front", "pop_front", "front", "priority_queue", "queue", "deque", "putchar",
        "gets", "sqrt"
    };
	const int T = 1000;
	for (int i = 0; i <= T; i++) if (ks[i] != "") keys.insert(ks[i]);
}

vector<string> vec;
map<string, string> mp;
int CNT;

// mt19937 seed(chrono::steady_clock::now().time_since_epoch().count());
mt19937 seed((unsigned long long)new char);
#define random(l, r) uniform_int_distribution<long long>(l, r)(seed)


struct stringset{
	vector<string> ret={"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
	string preffix = "__int";
	int maxl = ret.size();
	string id(int x){
		if (x < 0) x = 0;
		if (x >= maxl) x = maxl - 1;
		return ret[x];
	}
} drr;

set<string> holder;
inline string gen() {
	string now;
	int len = random(2 + sqrt(20 / drr.maxl), 4 + sqrt(20 / drr.maxl));

	do {
		now = "";
		for (int i = 1; i <= len; i++) now += drr.id(random(0, drr.maxl - 1));
		if (drr.preffix == "") { // 无 preffix 时保证不以数字开头
			while (isdigit(now[0])) now =  drr.id(random(0, drr.maxl - 1)) + now;
		}
		now = drr.preffix + now;
	} while (holder.find(now) != holder.end());
	holder.insert(now);
	return now;
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("shit.cpp", "w", stdout);
	init();

	string ans = "";
	string s = "", F = ""; 
	bool on = 0;
	char ch;

	while (scanf("%c", &ch) != EOF) F += ch;

	int bras = 0;
	bool skiped = 0;
	// for (char ch: F) {
	for (int i = 0; i < int(F.length()) && (ch = F[i], true); i++) {
		if (ch == '\\') {
			ans += ch; ans += F[i + 1];
			i++;
			continue;
		}

		if (ch == '\"' || ch == '\'') bras ^= 1;
		if (bras) { ans = ans + ch; continue; }

		if (ch == '#' && (F[i + 1] == 'i' || F[i + 1] == 'p')) { // 跳过 include / pragma 行
			ans += ch;
			skiped = 1;
			continue;
		}
		if (skiped && ch == '\n') {
			ans += ch;
			skiped = 0;
			continue;
		}
		if (skiped) {
			ans += ch;
			continue;
		}

		if (ok(ch)) on = 1, s += ch;
		else if (on) {
			if (isdigit(s[0]) || key(s)) ans += s;
			else {
				if (mp.find(s) != mp.end()) ans += mp[s];
				// else mp[s] = "#" + to_string(++CNT), ans += mp[s];
				else mp[s] = gen(), ans += mp[s];
			}
			ans += ch;
			on = 0, s = "";
		}
		else {
			ans += ch;
		}
	}

	cout << ans << endl;
}
