#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};

class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText 
{
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Rereversed : public DecoratedText
{
public:
    explicit Rereversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::string val = data;
        reverse(val.begin(), val.end());
        text_->render(val);
    }
};

//class Link : ...
//
//auto text_block = new Link(new Text());
//text_block->render("netology.ru", "Hello world");
//
//>> > <a href = netology.ru>Hello world< / a>

class Link : public DecoratedText {
public:
    explicit Link(std::string text_url, Text* text_descr) :
                  DecoratedText(text_descr), text_url_(text_url) {}
    void render(const std::string& data) const {
        std::cout << "<a href = " << text_url_ << ">";
        text_->render(data);
        std::cout << "</a>";
    }
private:
    std::string text_url_;
};

int main() {
    auto text_block = new Paragraph(new Text());
    text_block->render("Hello world");

    std::cout << std::endl;

    auto text_block2 = new Paragraph( new Rereversed(new Text()));
    text_block2->render("Hello world");

    std::cout << std::endl;

    auto text_block3 = new Link("netology.ru", new Text());
    text_block3->render("Hello world");
}
