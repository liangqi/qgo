/*
 * sgfparser.h
 */

#ifndef SGFPARSER_H
#define SGFPARSER_H

#include "../globals.h"
#include "tree.h"

#include <QtCore>

/*
class BoardHandler;
class Tree;
class QTextStream;
class Move;
struct ASCII_Import;
class XMLParser;
class GameData;
*/
class SGFParser
{
public:
	SGFParser(Tree *tree);
	~SGFParser();
	QString loadFile(const QString &fileName);
	GameData * initGame(const QString &toParse, const QString &fileName);

	bool parse(const QString &fileName, const QString &filter=0, bool fastLoad=false);

	bool doParse(const QString &toParseStr, bool fastLoad=false);
/*
	bool parseString(const QString &toParse);
	bool doWrite(const QString &fileName, Tree *tree);
	bool exportSGFtoClipB(QString *str, Tree *tree);
	bool parseASCII(const QString &fileName, ASCII_Import *charset, bool isFilename=true);
*/
protected:
//	QString loadFile(const QString &fileName);
	bool initStream(QTextStream *stream);
	int minPos(int n1, int n2, int n3);

//	bool doParse(const QString &toParseStr, bool fastLoad=false);

	bool corruptSgf(int where=0, QString reason=NULL);

	bool parseProperty(const QString &toParse, const QString &prop, QString &result);
/*
	void traverse(Move *t, GameData *gameData);
	void writeGameHeader(GameData *gameData);
	bool parseASCIIStream(QTextStream *stream, ASCII_Import *charset);
	bool doASCIIParse(const QString &toParse, int &y, ASCII_Import *charset);
	bool checkBoardSize(const QString &toParse, ASCII_Import *charset);
//	void convertOldSgf(QString &toParse);
	bool initStream(QTextStream *stream);
	bool writeStream(Tree *tree);
*/
private:
//	BoardHandler *boardHandler;
	QTextStream *stream;
	bool isRoot;
//	XMLParser *xmlParser;
	int asciiOffsetX, asciiOffsetY;
	Tree *tree;
};

#endif
