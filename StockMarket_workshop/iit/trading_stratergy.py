# Imports
import time
import pandas as pd
import talib as ta


class Stratergy(object):
    def download_data(self):
        # Download data from Exchange APIs for daily.
        # Let's assume that we got a CSV from exchange.
        # We will load data here into pandas and return the data.
        df = pd.read_csv("yesbank.csv")
        return df

    def buy(self):
        print("Buy")

    def sell(self):
        print("Sell")

    def trade(self):
        # Match condition.
        # Condition
        '''
        SMA 20 > SMA 50, then buy else sell the stock.
        '''
        df = self.download_data()
        sma30 = ta.SMA(df['Close Price'], timeperiod=20)
        sma50 = ta.SMA(df['Close Price'], timeperiod=30)

        if sma30.iloc[-1] < sma50.iloc[-1]:
            self.buy()
        else:
            self.sell()
    
    def is_market_open(self):
        return True


stratergy_instance = Stratergy()
while True:
    if stratergy_instance.is_market_open:
        stratergy_instance.trade()

    time.sleep(10)
