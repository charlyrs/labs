

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
  FileReader file;
  auto infoFromFile = file.ReadWords(file_path);
  for (const auto& i : infoFromFile){
    list_word_cards.PushBack(convert_string_to_word_card(i));
  }

}
WordCard *Vocabulary::convert_string_to_word_card(string str) {
  WordCard *card=new WordCard(str);
  return card;
}
void Vocabulary::make_frequency_vocab() {
  for (int i = 0; i < list_word_cards.Size(); ++i){
    for (int j=i; j< list_word_cards.Size(); j++){
      if (**list_word_cards[i]==**list_word_cards[j]){
        list_word_cards.Erase(j);
        (*list_word_cards[i])->IncCounter();
      }
    }

  }

}
map<string, size_t> Vocabulary::copy_to_map() {
  std::map<std::string, size_t> map;
  int size = list_word_cards.Size();
  for (int i=0; i<size; ++i){
    map[(*list_word_cards[i])->GetWord()]=(*list_word_cards[i])->GetCounter();
  }
  return map;
}
void Vocabulary::sort_words() {
  int size = list_word_cards.Size();
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if ( (*list_word_cards[i])->GetCounter()<(*list_word_cards[j])->GetCounter()) {
        std::swap(*list_word_cards[i],*list_word_cards[j]);
      }
    }
  }
}

#endif //KR2_GR1_KHOMYAKOVA_LILIYA__VOCABULARY_H_
