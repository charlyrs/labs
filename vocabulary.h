

#ifndef KR2_GR1_KHOMYAKOVA_LILIYA__VOCABULARY_H_
#define KR2_GR1_KHOMYAKOVA_LILIYA__VOCABULARY_H_
#include "word_card.h"
#include "bidirectional_list_on_array.h"
#include "map"
using namespace containers;
using std::map;

class Vocabulary {
 public:
  void read_file_to_cards(std::string file_path);
  WordCard *convert_string_to_word_card(string str);
  void make_frequency_vocab();
  void sort_words();
  map<string, size_t> copy_to_map();

 private:
  BiDirectionalListOnArray<WordCard *> list_word_cards;
};
void Vocabulary::read_file_to_cards(std::string file_path) {

}

#endif //KR2_GR1_KHOMYAKOVA_LILIYA__VOCABULARY_H_
