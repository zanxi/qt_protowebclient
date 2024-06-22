#include "hyphenator.h"
#include <QStringList>
#include <QDataStream>
#include <QRegularExpression>

QString utf(const char* sourcetext)
{
    return QString::fromUtf8(sourcetext);
};

namespace Hyphenation
{
Hyphenator::~Hyphenator()
{
}

void Hyphenator::hyphenate(HyphenatedWord& word)
{
    if (word.text().isEmpty()) {
        word._splitInfo = QStringList();
    } else if (word.isAbbreviation()) {
        word._splitInfo = QStringList(word.text());
    } else {
        word._splitInfo = doHyphenate(word.text());
    }
}

Hyphenator::Hyphenator()
{
}

void Hyphenator::hyphenate(HyphenatedPhrase& phrase)
{
    QStringList words = phrase.text().split(' ',
#if (QT_VERSION >= QT_VERSION_CHECK(5, 15, 0))
                                            Qt::SkipEmptyParts
#else
                                            QString::SkipEmptyParts
#endif
                                            ,
                                            Qt::CaseSensitive);
    for (QStringList::ConstIterator s = words.constBegin(); s != words.constEnd(); s++) {
        phrase._hyphenatedWords.append(HyphenatedWord(*s));
        hyphenate(phrase._hyphenatedWords[phrase._hyphenatedWords.count() - 1]);
    }
}

HyphenatedWord::HyphenatedWord()
    : HyphenatedItem()
{
}

HyphenatedWord::HyphenatedWord(const QString& text)
    : HyphenatedItem(text)
{
}

HyphenatedWord::~HyphenatedWord()
{
}

bool HyphenatedWord::isHyphenated() const
{
    return text().isEmpty() || _splitInfo.count() > 0;
}

QStringList HyphenatedWord::splitInfo() const
{
    return _splitInfo;
}

bool HyphenatedWord::isAbbreviation() const
{
    return Hyphenation::isAbbreviation(text());
}

HyphenatedWord& HyphenatedWord::operator=(const HyphenatedWord& item)
{
    if (&item != this) {
        HyphenatedItem::operator=(item);
        _splitInfo = item._splitInfo;
    }
    return *this;
}

HyphenatedPhrase::HyphenatedPhrase()
    : HyphenatedItem()
{
}

HyphenatedPhrase::HyphenatedPhrase(const QString& text)
    : HyphenatedItem(text)
{
}

HyphenatedPhrase::~HyphenatedPhrase()
{
}

bool HyphenatedPhrase::isHyphenated() const
{
    return text().isEmpty() || _hyphenatedWords.count() > 1;
}

QVector<HyphenatedWord> HyphenatedPhrase::hyphenatedWords() const
{
    return _hyphenatedWords;
}

HyphenatedPhrase& HyphenatedPhrase::operator=(const HyphenatedPhrase& item)
{
    if (&item != this) {
        HyphenatedItem::operator=(item);
        _hyphenatedWords = item._hyphenatedWords;
    }
    return *this;
}

HyphenatedItem::HyphenatedItem()
{
}

HyphenatedItem::HyphenatedItem(const QString& text)
    : _text(text.simplified())
{
}

HyphenatedItem::~HyphenatedItem()
{
}

QString HyphenatedItem::text() const
{
    return _text;
}

bool HyphenatedItem::isEmpty() const
{
    return _text.isEmpty();
}

HyphenatedItem& HyphenatedItem::operator=(const HyphenatedItem& item)
{
    if (&item != this) {
        _text = item._text;
    }
    return *this;
}

QDataStream& operator<<(QDataStream& stream, const HyphenatedWord& data)
{
    return stream << data._text << data._splitInfo;
}

QDataStream& operator>>(QDataStream& stream, HyphenatedWord& data)
{
    return stream >> data._text >> data._splitInfo;
}

bool isAbbreviation(const QString& s)
{
    /* Свойства аббревиатуры (условия "или"):
     * 1. Содержит только буквенные символы и все они заглавные. Может содержать дефисы и точки
     * 2. Содержит любые не буквенные символы, за исключением дефиса и точки */

    static const QRegularExpression re1(utf(R"(^[А-Я|A-Z|\-Ё\.]*$)"),
            QRegularExpression::UseUnicodePropertiesOption); // только буквенные заглавные символы, дефис или точка
    static const QRegularExpression re2(utf(R"(^[А-Я|а-я|A-Z|a-z|\-ёЁ\.]*$)"),
            QRegularExpression::UseUnicodePropertiesOption); // только символы, дефис или точка

    return re1.match(s).hasMatch() || !re2.match(s).hasMatch();
}
} // namespace Hyphenation
