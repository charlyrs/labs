
#ifndef KR2_GR1_KHOMYAKOVA_LILIYA__WORD_CARD_H_
#define KR2_GR1_KHOMYAKOVA_LILIYA__WORD_CARD_H_

#include <string>
using std::string;
class WordCard {
 public:
  WordCard();
  WordCard(string &);

  WordCard(const WordCard &);
  WordCard &operator=(WordCard &other);

  WordCard(WordCard &&);
  WordCard &operator=(WordCard &&other);

  ~WordCard() = default;

  string GetWord() const;
  size_t GetCounter() const;

  void IncCounter();

  bool operator==(WordCard &other) const;
  bool operator!=(WordCard &other) const;

  bool operator<(WordCard &first) const;

 private:
  string word_;
  size_t counter_;
};
WordCard::WordCard() {
  word_ = "";
  counter_ = 0;
}
WordCard::WordCard(string &s) {
  word_ = s;
  counter_ = 1;
}
WordCard::WordCard(const WordCard &s) {
  word_ = s.word_;
  counter_ = s.counter_;
}
size_t WordCard::GetCounter() const {
  return counter_;
}
string WordCard::GetWord() const {
  return word_;
}
void WordCard::IncCounter() {
  counter_++;
}
WordCard &WordCard::operator=(WordCard &other) {
  if (this == &other) return *this;
  word_ = other.word_;
  counter_ = other.counter_;
  return *this;
}
WordCard::WordCard(WordCard &&other) {
  word_ = other.word_;
  counter_ = other.counter_;
  other.word_ = "";
  other.counter_ = 0;

}
WordCard &WordCard::operator=(WordCard &&other) {
  if (this == &other) return *this;
  word_ = other.word_;
  counter_ = other.counter_;
  other.word_ = "";
  other.counter_ = 0;
  return *this;
}
bool WordCard::operator==(WordCard &other) const {
  if (counter_ != other.counter_)
    return false;
  if (word_ == other.word_)
    return true;
  else
    return false;
}
bool WordCard::operator!=(WordCard &other) const {
  return !(*this == other);
}
bool WordCard::operator<(WordCard &first) const {
  if (counter_<first.counter_) return true;
  else return false;
}

#endif //KR2_GR1_KHOMYAKOVA_LILIYA__WORD_CARD_H_
