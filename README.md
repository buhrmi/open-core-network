# NOTE: This experiment is not in active development anymore and the servers have been taken down. Currently investigating a re-implementation  including the [web app](http://github.com/buhrmi/open-core-webapp) if I can scrap together some funds.

[![Build Status](https://travis-ci.org/open-core/network.svg?branch=master)](https://travis-ci.org/open-core/network)

> Genesis 1:27 - "So God created man in his own image, in the image of God he created him; male and female he created them."

# open-core/network

The Open Core Network is a network of connected peers that work together to maintain consensus over the state of a globally synchronized cryptographic ledger. Users can create, sign and submit transactions into the network and query its replicated database for information.

In Open Core, network forks are an encouraged, recognized, natural way to express disagreement among peers. They are not viewed as a harmful event.

Users and developers can interact with the network in the following ways:

* Through the official [open-core webapp](http://github.com/open-core/webapp)
* Through client libraries, currently for [Ruby](http://github.com/stellar/ruby-stellar-base), [Javascript](http://github.com/stellar/js-stellar-base) and [Go](https://github.com/stellar/go-stellar-base)
* Through an instance of the [Stellar Horizon API](http://github.com/stellar/horizon) server running against the Open Core Network
* Directly accessing the Postgres SQL database (read-only)

# Origins

The Open Core Network is a fork of the [Stellar Consensus](http://www.stellar.org/galaxy) Protocol that

- Does not have a native currency
- Does not have a central authority
- Does not have inflation
- Does not have transaction fees
- Does not need a "createAccount" transaction
- Does not have a root account
- Does not have a notion of an unsafe quorum
- Starts with a blank genesis ledger
- Is truly open

# Getting Started

## Warning: This prototype requires Postgres 9.5

The code is using Postgres 9.5 `ON CONFLICT UPDATE` (aka upserts) feature. Your app will crash if you attempt to run against an earlier version.

Installation instructions ---> [HERE](https://github.com/buhrmi/core/blob/master/INSTALL.md)

After installation, use [this configuration file](https://github.com/buhrmi/core/blob/master/docs/open-core.cfg) to configure your node to connect to the network. Note that this config file pre-configures my personal validator node (validator.open-core.org) in the quorum. DO NOT USE IT if you don't trust this node.

# Running tests against postgreSQL

There are two options.  The easiest is to have the test suite just
create a temporary postgreSQL database cluster in /tmp and delete it
after the test.  That will happen by default if you run `make check`.

You can also create a temporary database cluster manually, by running
`./src/test/selftest-pg bash` to get a shell, then running tests
manually.  The advantage of this is that you can examine the database
log in `$PGDATA/pg_log/` after running tests, as well as manually
inspect the database with `psql`.

# Contributing

Just do your best! If you have any questions, join us in the developer chat at [Slack](https://stellar-public.slack.com/messages/dev/) and ask away.

# License

Yes. Check the license file for information.
