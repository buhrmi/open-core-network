#pragma once

// Copyright 2014 Stellar Development Foundation and contributors. Licensed
// under the Apache License, Version 2.0. See the COPYING file at the root
// of this distribution or at http://www.apache.org/licenses/LICENSE-2.0

#include "ledger/EntryFrame.h"
#include <functional>

namespace soci
{
class session;
}

namespace stellar
{
class ManageOfferOpFrame;
class StatementContext;

class OfferFrame : public EntryFrame
{
    static void
    loadOffers(StatementContext& prep,
               std::function<void(LedgerEntry const&)> offerProcessor);

    double computePrice() const;

    OfferEntry& mOffer;

    OfferFrame(OfferFrame const& from);

    void storeUpdateHelper(LedgerDelta& delta, Database& db, bool insert);

  public:
    typedef std::shared_ptr<OfferFrame> pointer;

    enum OfferFlags
    {
        PASSIVE_FLAG = 1
    };

    OfferFrame();
    OfferFrame(LedgerEntry const& from);

    OfferFrame& operator=(OfferFrame const& other);

    EntryFrame::pointer
    copy() const override
    {
        return EntryFrame::pointer(new OfferFrame(*this));
    }

    Price const& getPrice() const;
    int64_t getAmount() const;
    AccountID const& getSellerID() const;
    Asset const& getBuying() const;
    Asset const& getSelling() const;
    uint64 getOfferID() const;
    uint32 getFlags() const;

    OfferEntry const&
    getOffer() const
    {
        return mOffer;
    }
    OfferEntry&
    getOffer()
    {
        return mOffer;
    }

    static bool isValid(OfferEntry const& oe);
    bool isValid() const;

    // Instance-based overrides of EntryFrame.
    void storeDelete(LedgerDelta& delta, Database& db) const override;
    void storeChange(LedgerDelta& delta, Database& db) override;
    void storeAdd(LedgerDelta& delta, Database& db) override;

    // Static helpers that don't assume an instance.
    static void storeDelete(LedgerDelta& delta, Database& db,
                            LedgerKey const& key);
    static bool exists(Database& db, LedgerKey const& key);
    static uint64_t countObjects(soci::session& sess);

    // database utilities
    static pointer loadOffer(AccountID const& accountID, uint64_t offerID,
                             Database& db);

    static void loadBestOffers(size_t numOffers, size_t offset,
                               Asset const& pays, Asset const& gets,
                               std::vector<OfferFrame::pointer>& retOffers,
                               Database& db);

    static void loadOffers(AccountID const& accountID,
                           std::vector<OfferFrame::pointer>& retOffers,
                           Database& db);

    static void dropAll(Database& db);
    static const char* kSQLCreateStatement1;
    static const char* kSQLCreateStatement2;
    static const char* kSQLCreateStatement3;
    static const char* kSQLCreateStatement4;
};
}
