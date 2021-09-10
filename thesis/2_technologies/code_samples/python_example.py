# Funkcja zwracająca wpisy ze słownika wejściowego, których wartość zawiera słowa 
# kluczowe USBRM, USB, Relay, Multiplexer. Jeżeli są one zawarte, to analizowany 
# element odpowiada wykorzystywanemu w projekcie multiplekserowi. 
def execute(udevadm_dict):
    result = []
    # iteracja po wszystkich elementach wejściowego słownika
    for device_path, output in udevadm_dict.items():
        # jeśli wartość zawiera wszystkie słowa kluczowe z listy
        if all(item in output for item in ["USBRM", "USB", "Relay", "Multiplexer"]):
            # pozyskanie numeru seryjnego za pomocą wyrażenia regularnego
            serial = search(r'=(USBRM[^-\n]*)\n', output).group(1)
            # dodanie informacji o multiplekserze do wynikowej struktury
            result.append({"device_path": device_path, "serial": serial})
    return result