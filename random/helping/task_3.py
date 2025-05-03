import matplotlib.pyplot as crtaj

dani_u_sedmici = ["pon", "uto", "sre", "cet", "pet", "sub", "ned"]
maksimalne_dnev_temp = [11, 10, 8, 6, 9, 12, 7]

crtaj.bar(dani_u_sedmici, maksimalne_dnev_temp) #iscrtava stubicasti dijagram
crtaj.title("Maksimalne Dnevne Temperature")
crtaj.xlabel("Dani u Sedmici")
crtaj.ylabel("Vrednosti Maksimalnih Dnevnih Temperatura (C)")
crtaj.show()
crtaj.close()

