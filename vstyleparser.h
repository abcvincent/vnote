#ifndef VSTYLEPARSER_H
#define VSTYLEPARSER_H

#include <QPalette>
#include <QVector>
#include <QString>
#include "hgmarkdownhighlighter.h"

extern "C" {
#include "utils/peg-highlight/pmh_definitions.h"
#include "utils/peg-highlight/pmh_styleparser.h"
}

class QColor;
class QBrush;

class VStyleParser
{
public:
    VStyleParser();
    ~VStyleParser();

    void parseMarkdownStyle(const QString &styleStr);
    QVector<HighlightingStyle> fetchMarkdownStyles(const QFont &baseFont) const;
    QPalette fetchMarkdownEditorStyles(const QPalette &basePalette) const;

private:
    QColor QColorFromPmhAttr(pmh_attr_argb_color *attr) const;
    QBrush QBrushFromPmhAttr(pmh_attr_argb_color *attr) const;
    QTextCharFormat QTextCharFormatFromAttrs(pmh_style_attribute *attrs,
                                             const QFont &baseFont) const;
    QString filterAvailableFontFamily(const QString &familyList) const;
    pmh_style_collection *markdownStyles;
};

#endif // VSTYLEPARSER_H