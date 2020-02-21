// Copyright (c) 2011-2014 The Sunlightcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SUNLIGHTCOIN_QT_SUNLIGHTCOINADDRESSVALIDATOR_H
#define SUNLIGHTCOIN_QT_SUNLIGHTCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class SunlightcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SunlightcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Sunlightcoin address widget validator, checks for a valid sunlightcoin address.
 */
class SunlightcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SunlightcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // SUNLIGHTCOIN_QT_SUNLIGHTCOINADDRESSVALIDATOR_H
