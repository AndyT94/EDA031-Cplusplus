#ifndef TAGREMOVER_H
#define TAGREMOVER_H

class TagRemover {
public:
TagRemover(const std::istream& in);
void print(const std::ostream& out);

private:
  std::string text;
  void removeTags(const std::istream& in);
};

#endif
