#ifndef TAGREMOVER_H
#define TAGREMOVER_H

class TagRemover {
public:
TagRemover(std::istream& in);
void print(std::ostream& out);

private:
  std::string text;
  void removeTags(std::istream& in);
};

#endif
