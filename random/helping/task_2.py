import matplotlib.pyplot as crtaj

godine = [2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2020, 2021, 2022, 2023, 2024, 2025]
visina = [ 100,  105,  108,  110,  112,  115,  140,  145,  155,  180,  184,  185,  186,  186,  186,  186,  186,  186,  186,  186]

crtaj.plot(godine, visina)
crtaj.title("Visina kroz godine, od 7. godine zivota do danas.")
crtaj.xlabel("Godine")
crtaj.ylabel("Visina")
crtaj.show()
crtaj.close()
