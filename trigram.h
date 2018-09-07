#ifndef TRIGRAM_H
#define TRIGRAM_H

#include <string>

class trigram
{
	public:
		bool is_trigram(std::string phrase);
	private:
		int search(std::string phrase, int l, int r);

		int table_size = 727;

		std::string trigram_table[776] = {
"abl", "abo", "abr", "abs", "acc", "ach", "acr", "act", "add", "adm", "adv", "aer", "aff", "afr", "aft", "aga", "age", "ago", "ahe", "air", "ali", "all", "alm", "alo", "alr", "als", "alt", "alw", "am", "ame", "amo", "and", "ang", "ani", "ano", "ans", "any", "apa", "app", "apr", "are", "arg", "arm", "arr", "art", "asi", "ask", "asl", "ate", "atm", "att", "aud", "aug", "aut", "ave", "avo", "awa", "bab", "bac", "bad", "bag", "bal", "ban", "bas", "bat", "be", "bea", "bec", "bed", "bee", "bef", "beg", "beh", "bel", "bes", "bet", "bey", "bic", "big", "bik", "bil", "bir", "bit", "bla", "ble", "blo", "blu", "boa", "bod", "bon", "boo", "bor", "bot", "bou", "box", "boy", "bra", "bre", "bri", "bro", "bui", "bur", "bus", "but", "buy", "by", "cak", "cal", "cam", "can", "cap", "car", "cas", "cat", "cau", "cen", "cer", "cha", "che", "chi", "cho", "chu", "cir", "cit", "cla", "cle", "cli", "clo", "coa", "cof", "coi", "col", "com", "con", "coo", "cop", "cor", "cos", "cou", "cov", "cow", "cre", "cri", "cro", "cry", "cup", "cur", "cus", "cut", "dad", "dai", "dam", "dan", "dar", "dat", "dau", "day", "dea", "dec", "dee", "def", "deg", "del", "dem", "den", "dep", "des", "det", "dev", "dic", "did", "die", "dif", "dig", "din", "dir", "dis", "div", "do", "doc", "doe", "dog", "dol", "don", "doo", "dou", "dow", "doz", "dra", "dre", "dri", "dro", "dru", "dry", "due", "dur", "dus", "dut", "eac", "ear", "eas", "eat", "edu", "eff", "egg", "eig", "eit", "ele", "els", "emp", "end", "ene", "eng", "enj", "eno", "ent", "equ", "err", "esp", "eur", "eve", "exa", "exc", "exe", "exp", "eye", "fac", "fai", "fal", "fam", "far", "fas", "fat", "fea", "feb", "fed", "fee", "fel", "few", "fie", "fif", "fig", "fil", "fin", "fir", "fis", "fiv", "fix", "fla", "fle", "fli", "flo", "fly", "fol", "foo", "for", "fou", "fra", "fre", "fri", "fro", "fru", "ful", "fun", "fut", "gai", "gam", "gar", "gas", "gat", "gav", "gen", "ger", "get", "gir", "giv", "gla", "go", "god", "goi", "gon", "goo", "got", "gov", "gra", "gre", "gro", "gua", "gue", "gui", "gun", "hab", "had", "hai", "hal", "han", "hap", "har", "has", "hat", "hav", "he", "hea", "hei", "hel", "her", "hi", "hid", "hig", "hil", "him", "hir", "his", "hit", "hol", "hom", "hon", "hop", "hor", "hos", "hot", "hou", "how", "hum", "hun", "hur", "hus", "i", "ice", "ide", "if", "ima", "imm", "imp", "in", "inc", "ind", "inf", "ins", "int", "inv", "iro", "is", "isl", "it", "its", "jan", "jap", "job", "joi", "jud", "jul", "jum", "jun", "jus", "k'c", "kab", "kac", "kad", "kag", "kai", "kaj", "kak", "kam", "kan", "kap", "kar", "kas", "kat", "kau", "kaw", "kay", "kaz", "kbj", "kct", "ke", "kea", "kec", "ked", "kee", "kef", "keg", "kei", "kem", "ken", "kep", "kes", "ket", "kev", "kew", "kex", "key", "kf", "kff", "kft", "kh", "kib", "kic", "kid", "kie", "kif", "kig", "kik", "kil", "kim", "kin", "kis", "kit", "kiv", "kka", "kld", "kn", "knc", "kne", "kni", "knl", "kno", "ko", "kob", "koc", "kod", "koi", "kom", "kon", "koo", "kor", "kos", "kot", "kou", "kov", "kow", "kpe", "kpi", "kpp", "kr", "kra", "krd", "kth", "kuc", "kum", "kun", "kur", "kus", "kut", "kve", "kwn", "ky", "kyi", "kys", "pac", "pag", "pai", "pap", "par", "pas", "pat", "pay", "pea", "pen", "peo", "per", "pho", "pic", "pie", "pin", "pip", "pla", "ple", "poc", "poi", "pol", "poo", "pop", "pos", "pot", "pou", "pow", "pra", "pre", "pri", "pro", "pub", "pul", "pup", "pur", "pus", "put", "qua", "que", "qui", "rac", "rad", "rai", "ran", "rap", "rat", "rea", "rec", "red", "ref", "reg", "rel", "rem", "rep", "req", "res", "ret", "ric", "rid", "rig", "rin", "ris", "riv", "roa", "roc", "rod", "rol", "roo", "ros", "rou", "row", "rul", "run", "rus", "sad", "saf", "sai", "sal", "sam", "san", "sat", "sav", "saw", "say", "sce", "sch", "sci", "sco", "sea", "sec", "see", "sel", "sen", "sep", "ser", "set", "sev", "sex", "sha", "she", "shi", "sho", "shu", "sic", "sid", "sig", "sil", "sim", "sin", "sis", "sit", "six", "siz", "ski", "sky", "sle", "sli", "slo", "sma", "sme", "smi", "smo", "sno", "so", "soa", "soc", "sof", "soi", "sol", "som", "son", "soo", "sor", "sou", "spa", "spe", "spi", "spo", "spr", "squ", "sta", "ste", "sti", "sto", "str", "stu", "sty", "sub", "suc", "sud", "suf", "sug", "sum", "sun", "sup", "sur", "swa", "swe", "swi", "swu", "sys", "tab", "tak", "tal", "tas", "tau", "tax", "tea", "tee", "tel", "tem", "ten", "ter", "tes", "tha", "the", "thi", "tho", "thr", "thu", "tic", "tie", "til", "tim", "tir", "tit", "to", "tod", "tog", "tol", "tom", "ton", "too", "top", "tor", "tot", "tou", "tow", "tra", "tre", "tri", "tro", "tru", "try", "tue", "tur", "tv", "twe", "twi", "two", "tyi", "typ", "una", "unc", "und", "uni", "unl", "unt", "up", "upo", "us", "use", "usu", "vai", "vak", "val", "van", "var", "vas", "vat", "vav", "vay", "ve", "vea", "ved", "vee", "veg", "vei", "vel", "ven", "ver", "ves", "vet", "vha", "vhe", "vhi", "vho", "vhy", "vid", "vie", "vif", "vil", "vin", "vir", "vis", "vit", "viv", "vma", "voi", "vok", "vol", "vom", "von", "voo", "vor", "vot", "vou", "vri", "vro", "yar", "yea", "yel", "yen", "yes", "yet", "you", "zer"
		};
};

#endif
