# 📘 KEYWORD_GUIDE.md – *Patnubay sa mga Terminolohiya*

Ang dokumentong ito ay naglalaman ng mga piling *pinasadyang terminolohiya* at *neolohismo* na ginagamit sa buong dokumentasyon ng aklatang **MuntingTibok**. Layunin nitong magsilbing glosaryo upang magkaroon ng iisang kahulugan ang mga salitang teknikal na inangkop o nilikha para sa proyektong ito.

Sa pagsasagawa ng mga teknikal na proyekto, mahalaga ang paggamit ng wika na hindi lamang tumpak, kundi pati na rin ingklusibo at makatarungan. Dahil dito, ang ilang mga tradisyonal na terminolohiya, gaya ng "master-slave" at "on-off", ay pinapalitan ng mas neutral at walang diskriminasyong wika. Halimbawa, ang paggamit ng "pindí" sa halip na "patay" ay naglalayong gawing mas teknikal at positibo ang mga pahayag ng estado sa mga sistema.

---

## 🧾 Talaan ng mga Terminolohiya (A-Z)

| Termino | Ingles | Kahulugan |
|--------|-----------|-----------|
| **aklatan** | *library* | Tumutukoy sa isang *library* sa konteksto ng Arduino o C++, na binubuo ng mga klase at header files para sa tiyak na layunin. |
| **aktibong estado** | *active state* | Lohikal na HIGH (`true`) o LOW (`false`) na antas ng signal na nagpapahiwatig ng *"ON state"*. |
| **antas ng tibok** | *heartbeat level* | Tumutukoy sa iba't ibang mga predefined na delay o interval ng tibok (heartbeat) ng isang sistema. Halimbawa, sa aklatang **MuntingTibok**, ang antas ng tibok ay kinakatawan ng mga enum values tulad ng `NORMAL`, `WARNING`, `CRITICAL`, at `EMERGENCY`, bawat isa ay may partikular na halaga ng delay sa milliseconds. |
| **katayuan ng sistema** | *system status* | Kalagayang pangkabuoan ng isang proyekto o sistema, na ipinahahayag sa pamamagitan ng tibok. |
| **pindí** | *off state* | Pansamantalang paghinto ng operasyon, gaya ng paghinto ng heartbeat signal upang magpahiwatig ng *inactive state*. |
| **tibok** | *heartbeat* | Isang *pulsating signal* o kilos na paulit-ulit (hal. blinking ng LED) na sumasagisag sa aktibong operasyon, kalusugan, o alerto ng sistema. |
| **tikwas** | *toggle* | Isang teknikal na salin para sa *toggle* o *activate/deactivate*, karaniwang ginagamit sa konteksto ng pagpipindi o pagbubuhay ng isang feature sa runtime. |

---

> 🔍 *Tandaan:* Ang mga terminong ito ay bahagi ng intelektuwalisasyon ng wikang teknikal sa larangan ng electronics at embedded systems. Maaari itong palawakin habang lumalawak ang dokumentasyon ng Proyektong LundayHangin.
