# 11. zadanie: pismenkovy graf
# autor: Peter Kendra
# datum: 18.5.2024

class Graph:
    def __init__(self, file_name):
        self.vrcholy = set()
        self.hrany = {}

        with open(file_name, "r", encoding="utf8") as f:
            line = f.readline().strip()

            while line:
                if line.count(":") == 1:
                    self.vrcholy.add(line.split(":")[0])
                    self.vrcholy.add(line.split(":")[1])
                    self.hrany[line] = None
                    self.hrany[line.split(":")[1] + ":" + line.split(":")[0]] = None
                else:
                    self.vrcholy.add(line.split(":")[0])
                    self.vrcholy.add(line.split(":")[2])
                    self.hrany[line.split(":")[0] + ":" + line.split(":")[2]] = line.split(":")[1]
                    self.hrany[line.split(":")[2] + ":" + line.split(":")[0]] = line.split(":")[1]
                line = f.readline().strip()

    def get_edge(self, v1, v2):
        try:
            if self.hrany[str(v1)+":"+str(v2)] is None:
                return ""
            else:
                return self.hrany[str(v1)+":"+str(v2)]
        except KeyError:
            return None

    def vertices(self):
        return self.vrcholy

    def solve(self, v1):
        self.max_cesty = set()
        self.max_cesta = 0
        hrany = self.hrany.keys()

        def rek(v: str, d: int, used: set, cesta: list):
            moje_hrany = set()
            for i in hrany:
                if i[:len(v)] == v:
                    if i not in used:
                        moje_hrany.add(i)

            cesta.append(v)

            if d > self.max_cesta:
                self.max_cesta = d
                self.max_cesty = set()
            if d == self.max_cesta and d != 0:
                self.max_cesty.add(tuple(cesta))

            for i in moje_hrany:
                if d % 3 == 0:
                    if self.hrany[i] == "a" or self.hrany[i] is None:
                        used.add(i)
                        used.add(i.split(":")[1] + ":" + i.split(":")[0])

                        rek(i.split(":")[1], d+1, used, cesta)

                        used.remove(i)
                        used.remove(i.split(":")[1] + ":" + i.split(":")[0])
                        cesta.pop()
                elif d % 3 == 1:
                    if self.hrany[i] == "b" or self.hrany[i] is None:
                        used.add(i)
                        used.add(i.split(":")[1] + ":" + i.split(":")[0])

                        rek(i.split(":")[1], d + 1, used, cesta)

                        used.remove(i)
                        used.remove(i.split(":")[1] + ":" + i.split(":")[0])
                        cesta.pop()
                else:
                    if self.hrany[i] == "c" or self.hrany[i] is None:
                        used.add(i)
                        used.add(i.split(":")[1] + ":" + i.split(":")[0])

                        rek(i.split(":")[1], d + 1, used, cesta)

                        used.remove(i)
                        used.remove(i.split(":")[1] + ":" + i.split(":")[0])
                        cesta.pop()

        rek(v1, 0, set(), [])
        a = ('akynole', 'dekoqyl', 'gyhewiw', 'iry', 'xog', 'jycudihow', 'qyvin', 'saf', 'otoho', 'mojiz', 'emo', 'tivyvisul', 'yvugefa', 'gimicyvuj', 'lykofofax', 'izulywu', 'mir', 'jonaw', 'ecohyvafi', 'wot', 'sek', 'ejojuje', 'acu', 'yvisa', 'aju', 'egoki', 'obe', 'carasugec', 'usedosila', 'cezinucag', 'nut', 'giz', 'xytapem', 'ari', 'magys', 'qakylaj', 'nit', 'igi', 'ifobusu', 'xolyt', 'zegyxykeb', 'nyqybit', 'lek', 'nepulut', 'ubiza', 'utuqygo', 'esije', 'oce', 'boqyh', 'vob', 'gud', 'obuny', 'yvoxumo', 'ajy', 'gutusud', 'vazukyzum', 'povih', 'yhy', 'ybe', 'qeteqywuq', 'onecusy', 'ugicubymo', 'taryvuf', 'gyqupynis', 'unohesigy', 'xirej', 'najokeb', 'yqybeguwi', 'abogu', 'yqoxugeke', 'oboluku', 'tyruwisys', 'jehep', 'vuwov', 'etuxuvezu', 'nic', 'jizogor', 'xuhasahaz', 'aregepi', 'zaliq', 'qexoh', 'aqysa', 'lebobyrah', 'ora', 'elygi', 'axutovi', 'hafin', 'muv', 'ufyguze', 'ipakizo', 'onydo', 'ixete', 'sesel', 'xaxol', 'pydiqixah', 'ijyhi', 'mykyxov', 'vilol', 'ufy', 'dyrosyt', 'itetimi', 'cokysysiq', 'vecad', 'qef', 'olaxaviha', 'upu', 'kud', 'ywure', 'toj', 'tud', 'yra', 'witacet', 'imuhawa', 'afumywy', 'edi', 'qakideq', 'tohorynic', 'ytycyga', 'mytaquw', 'adadi', 'xev', 'cin', 'kehekyv', 'idujena', 'taheduxit', 'edicu', 'nisam', 'dobar', 'zyxepod', 'cyt', 'avehyvu', 'apozowowe', 'ciliw', 'uzonecafe', 'evasina', 'vituw', 'mycyr', 'yhume', 'okevyle', 'syv', 'eviti', 'oqeri', 'faj', 'ici', 'caxybyf', 'qev', 'epabevoqy', 'xaqeqyv', 'vuc', 'avaquludu', 'bin', 'iryharo', 'qogocif', 'aqodify', 'eroryxe', 'jedyx', 'ref', 'ziwador', 'dygaryt', 'ofo', 'fiquhocec', 'nav', 'favam', 'yvyso', 'mozodyjal', 'lur', 'kobepocon', 'owupicifu', 'saf', 'axypoku', 'yqejymi', 'memyduwoh', 'dybut', 'osyga', 'edikupe', 'lipilyx', 'xyq', 'fohur', 'ywy', 'ekera', 'mihyq', 'egy', 'rojaten', 'dovibaq', 'yle', 'ado', 'lev', 'yjukosuba', 'oze', 'aty', 'akube', 'yxihefuqi', 'ibogo', 'aqe', 'vuripop', 'vamufujaz', 'bah', 'osohy', 'zyb', 'ybycygopi', 'ajelytowo', 'sylel', 'ifixepe', 'peweqes', 'aximi', 'opiniwa', 'fav', 'ebeha', 'kuz', 'vygacahas', 'onekubyve', 'hyq', 'nosifyxip', 'dirup', 'nujyfejeh', 'veqalyc', 'jiwuniq', 'kykaj', 'ihudiqera', 'jim', 'otumuno', 'ami', 'tad', 'kocofiw', 'uro', 'zejibem', 'linucup', 'abybeqa', 'ipery', 'apohi', 'hecul', 'dibij', 'numud', 'enu', 'oluga', 'duvomiv', 'tukohyc', 'uwi', 'johusar', 'vudopux', 'byjiviziz', 'odedi', 'okysywu', 'sikyv', 'zegikodew', 'rehojugap', 'zavacilaq', 'ine', 'ymumy', 'iviryki', 'osiwu', 'axequkuco', 'anagadadi', 'suwakex', 'xox', 'ponem', 'yzo', 'jafek', 'bihumypeb', 'vyk', 'get', 'kocepigyk', 'mul', 'ulila', 'oqako', 'ulagy', 'duqajocoz', 'nigyx', 'usa', 'burod', 'gym', 'axosisumu', 'tax', 'uvunynyqy', 'lopepiref', 'tijopos', 'ase', 'ebise', 'juwug', 'rypij', 'manewok', 'yhutu', 'elasuba', 'pefam', 'iripo', 'jekoxegez', 'deqekutyt', 'yjysapi', 'ino', 'uxipyfypo', 'pyluj', 'romyw', 'rivalisuq', 'yhuvynezy', 'ocycowomo', 'uje', 'obomo', 'hupac', 'eno', 'hygyqujil', 'cufaric', 'alidybo', 'uwunyta', 'ilukevisa', 'wamelel', 'icorezevi', 'udikukuso', 'won', 'nek', 'gateciber', 'exaciwa', 'ryvas', 'alywa', 'upapo', 'ydu', 'pap', 'recutapag', 'jehyc', 'ufakacivu', 'ymuci', 'kebohikag', 'gugan', 'zumah', 'fycij', 'lipifanem', 'yhazy', 'fiq', 'uxohoty', 'ysofe', 'gejuj', 'gozojuf', 'zukos', 'hyjegot', 'ocy', 'iwinuby', 'ipawefiga', 'mog', 'videfir', 'ryvyrybuz', 'ukuji', 'ysu', 'gobed', 'lozatoxam', 'abe', 'coriwoz', 'zejev', 'kepokaj', 'kutyryz', 'zyp', 'ulypu', 'weduponyl', 'xor', 'ivobubu', 'wyqocys', 'ojaqysi', 'iwe', 'belinuc', 'uxecidelo', 'uluge', 'dysorac', 'oragake', 'ysigy', 'usofypijy', 'yfewopi', 'isufy', 'ixohobixu', 'zeg', 'jirydah', 'tar', 'lileqax', 'ejovokewy', 'arite', 'ijotofuve', 'ysubugaso', 'osoqyve', 'dadar', 'akynole')
        b = ('akynole', 'dekoqyl', 'gyhewiw', 'iry', 'xog', 'jycudihow', 'qyvin', 'saf', 'xubid', 'kobepocon', 'lur', 'gunafuraq', 'yvyso', 'favam', 'bequxik', 'fiquhocec', 'ofo', 'ysepyve', 'ziwador', 'ref', 'ywu', 'eroryxe', 'aqodify', 'saquj', 'iryharo', 'bin', 'efitehi', 'vuc', 'xaqeqyv', 'hokigag', 'qev', 'caxybyf', 'aweko', 'faj', 'oqeri', 'rip', 'syv', 'okevyle', 'malimos', 'mycyr', 'vituw', 'cofaxorej', 'uzonecafe', 'ciliw', 'ytore', 'avehyvu', 'cyt', 'ina', 'dobar', 'nisam', 'yqy', 'taheduxit', 'idujena', 'kigog', 'cin', 'xev', 'ymebadano', 'mytaquw', 'ytycyga', 'hiz', 'qakideq', 'edi', 'aze', 'dybut', 'memyduwoh', 'kav', 'axypoku', 'safaxos', 'otoho', 'mojiz', 'emo', 'tivyvisul', 'yvugefa', 'gimicyvuj', 'lykofofax', 'izulywu', 'mir', 'jonaw', 'ecohyvafi', 'wot', 'sek', 'ejojuje', 'acu', 'yvisa', 'aju', 'egoki', 'obe', 'carasugec', 'usedosila', 'cezinucag', 'nut', 'giz', 'xytapem', 'ari', 'magys', 'qakylaj', 'nit', 'igi', 'ifobusu', 'xolyt', 'zegyxykeb', 'nyqybit', 'lek', 'nepulut', 'ubiza', 'utuqygo', 'esije', 'oce', 'boqyh', 'vob', 'gud', 'obuny', 'yvoxumo', 'ajy', 'gutusud', 'vazukyzum', 'povih', 'yhy', 'ybe', 'qeteqywuq', 'onecusy', 'ugicubymo', 'taryvuf', 'gyqupynis', 'unohesigy', 'xirej', 'najokeb', 'yqybeguwi', 'abogu', 'yqoxugeke', 'oboluku', 'tyruwisys', 'jehep', 'vuwov', 'etuxuvezu', 'nic', 'jizogor', 'xuhasahaz', 'aregepi', 'zaliq', 'qexoh', 'aqysa', 'lebobyrah', 'ora', 'elygi', 'axutovi', 'hafin', 'muv', 'ufyguze', 'ipakizo', 'onydo', 'ixete', 'sesel', 'xaxol', 'pydiqixah', 'ijyhi', 'mykyxov', 'vilol', 'ufy', 'dyrosyt', 'itetimi', 'cokysysiq', 'vecad', 'qef', 'olaxaviha', 'upu', 'kud', 'ywure', 'toj', 'tud', 'yra', 'witacet', 'imuhawa', 'afumywy', 'edi', 'lipilyx', 'xyq', 'fohur', 'ywy', 'ekera', 'mihyq', 'egy', 'rojaten', 'dovibaq', 'yle', 'ado', 'lev', 'yjukosuba', 'oze', 'aty', 'akube', 'yxihefuqi', 'ibogo', 'aqe', 'vuripop', 'vamufujaz', 'bah', 'osohy', 'zyb', 'ybycygopi', 'ajelytowo', 'sylel', 'ifixepe', 'peweqes', 'aximi', 'opiniwa', 'fav', 'ebeha', 'kuz', 'vygacahas', 'onekubyve', 'hyq', 'nosifyxip', 'dirup', 'nujyfejeh', 'veqalyc', 'jiwuniq', 'kykaj', 'ihudiqera', 'jim', 'otumuno', 'ami', 'tad', 'kocofiw', 'uro', 'zejibem', 'linucup', 'abybeqa', 'ipery', 'apohi', 'hecul', 'dibij', 'numud', 'enu', 'oluga', 'duvomiv', 'tukohyc', 'uwi', 'johusar', 'vudopux', 'byjiviziz', 'odedi', 'okysywu', 'sikyv', 'zegikodew', 'rehojugap', 'zavacilaq', 'ine', 'ymumy', 'iviryki', 'osiwu', 'axequkuco', 'anagadadi', 'suwakex', 'xox', 'ponem', 'yzo', 'jafek', 'bihumypeb', 'vyk', 'get', 'kocepigyk', 'mul', 'ulila', 'oqako', 'ulagy', 'duqajocoz', 'nigyx', 'usa', 'burod', 'gym', 'axosisumu', 'tax', 'uvunynyqy', 'lopepiref', 'tijopos', 'ase', 'ebise', 'juwug', 'rypij', 'manewok', 'yhutu', 'elasuba', 'pefam', 'iripo', 'jekoxegez', 'deqekutyt', 'yjysapi', 'ino', 'uxipyfypo', 'pyluj', 'romyw', 'rivalisuq', 'yhuvynezy', 'ocycowomo', 'uje', 'obomo', 'hupac', 'eno', 'hygyqujil', 'cufaric', 'alidybo', 'uwunyta', 'ilukevisa', 'wamelel', 'icorezevi', 'udikukuso', 'won', 'nek', 'gateciber', 'exaciwa', 'ryvas', 'alywa', 'upapo', 'ydu', 'pap', 'recutapag', 'jehyc', 'ufakacivu', 'ymuci', 'kebohikag', 'gugan', 'zumah', 'fycij', 'lipifanem', 'yhazy', 'fiq', 'uxohoty', 'ysofe', 'gejuj', 'gozojuf', 'zukos', 'hyjegot', 'ocy', 'iwinuby', 'ipawefiga', 'mog', 'videfir', 'ryvyrybuz', 'ukuji', 'ysu', 'gobed', 'lozatoxam', 'abe', 'coriwoz', 'zejev', 'kepokaj', 'kutyryz', 'zyp', 'ulypu', 'weduponyl', 'xor', 'ivobubu', 'wyqocys', 'ojaqysi', 'iwe', 'belinuc', 'uxecidelo', 'uluge', 'dysorac', 'oragake', 'ysigy', 'usofypijy', 'yfewopi', 'isufy', 'ixohobixu', 'zeg', 'jirydah', 'tar', 'lileqax', 'ejovokewy', 'arite', 'ijotofuve', 'ysubugaso', 'osoqyve', 'dadar', 'akynole')
        c = ('akynole', 'dadar', 'vokug', 'ysubugaso', 'ijotofuve', 'unuxukuji', 'ejovokewy', 'lileqax', 'wediz', 'jirydah', 'zeg', 'rehojugap', 'zavacilaq', 'ine', 'ymumy', 'iviryki', 'osiwu', 'axequkuco', 'anagadadi', 'suwakex', 'xox', 'ponem', 'yzo', 'jafek', 'bihumypeb', 'vyk', 'get', 'kocepigyk', 'mul', 'ulila', 'oqako', 'ulagy', 'duqajocoz', 'nigyx', 'usa', 'burod', 'gym', 'axosisumu', 'tax', 'uvunynyqy', 'lopepiref', 'tijopos', 'ase', 'ebise', 'juwug', 'rypij', 'manewok', 'yhutu', 'elasuba', 'pefam', 'iripo', 'jekoxegez', 'deqekutyt', 'yjysapi', 'ino', 'uxipyfypo', 'pyluj', 'romyw', 'rivalisuq', 'yhuvynezy', 'ocycowomo', 'uje', 'obomo', 'hupac', 'eno', 'hygyqujil', 'cufaric', 'alidybo', 'uwunyta', 'ilukevisa', 'wamelel', 'icorezevi', 'udikukuso', 'won', 'nek', 'gateciber', 'exaciwa', 'ryvas', 'alywa', 'upapo', 'ydu', 'pap', 'recutapag', 'jehyc', 'ufakacivu', 'ymuci', 'kebohikag', 'gugan', 'zumah', 'fycij', 'lipifanem', 'yhazy', 'fiq', 'uxohoty', 'ysofe', 'gejuj', 'gozojuf', 'zukos', 'hyjegot', 'ocy', 'iwinuby', 'ipawefiga', 'mog', 'videfir', 'ryvyrybuz', 'ukuji', 'ysu', 'gobed', 'lozatoxam', 'abe', 'coriwoz', 'zejev', 'kepokaj', 'kutyryz', 'zyp', 'ulypu', 'weduponyl', 'xor', 'ivobubu', 'wyqocys', 'ojaqysi', 'iwe', 'belinuc', 'uxecidelo', 'uluge', 'dysorac', 'oragake', 'ysigy', 'usofypijy', 'yfewopi', 'isufy', 'ixohobixu', 'zeg', 'sikyv', 'awojy', 'odedi', 'byjiviziz', 'ynybexari', 'johusar', 'uwi', 'epenabobi', 'duvomiv', 'oluga', 'ixehaby', 'numud', 'dibij', 'dalenyq', 'apohi', 'ipery', 'cix', 'linucup', 'zejibem', 'gupin', 'kocofiw', 'tad', 'qufybas', 'otumuno', 'jim', 'qetynabul', 'kykaj', 'jiwuniq', 'heg', 'nujyfejeh', 'dirup', 'lowomyn', 'hyq', 'onekubyve', 'utimajo', 'kuz', 'ebeha', 'ryjubaxaf', 'opiniwa', 'aximi', 'sorebyviz', 'ifixepe', 'sylel', 'rajyn', 'ybycygopi', 'zyb', 'nocef', 'bah', 'vamufujaz', 'owi', 'aqe', 'ibogo', 'apa', 'akube', 'aty', 'tumiv', 'yjukosuba', 'lev', 'isajomano', 'yle', 'dovibaq', 'zibijul', 'egy', 'mihyq', 'luwev', 'ywy', 'fohur', 'zofazosup', 'lipilyx', 'edikupe', 'aze', 'dybut', 'memyduwoh', 'kav', 'axypoku', 'safaxos', 'otoho', 'mojiz', 'emo', 'tivyvisul', 'yvugefa', 'gimicyvuj', 'lykofofax', 'izulywu', 'mir', 'jonaw', 'ecohyvafi', 'wot', 'sek', 'ejojuje', 'acu', 'yvisa', 'aju', 'egoki', 'obe', 'carasugec', 'usedosila', 'cezinucag', 'nut', 'giz', 'xytapem', 'ari', 'magys', 'qakylaj', 'nit', 'igi', 'ifobusu', 'xolyt', 'zegyxykeb', 'nyqybit', 'lek', 'nepulut', 'ubiza', 'utuqygo', 'esije', 'oce', 'boqyh', 'vob', 'gud', 'obuny', 'yvoxumo', 'ajy', 'gutusud', 'vazukyzum', 'povih', 'yhy', 'ybe', 'qeteqywuq', 'onecusy', 'ugicubymo', 'taryvuf', 'gyqupynis', 'unohesigy', 'xirej', 'najokeb', 'yqybeguwi', 'abogu', 'yqoxugeke', 'oboluku', 'tyruwisys', 'jehep', 'vuwov', 'etuxuvezu', 'nic', 'jizogor', 'xuhasahaz', 'aregepi', 'zaliq', 'qexoh', 'aqysa', 'lebobyrah', 'ora', 'elygi', 'axutovi', 'hafin', 'muv', 'ufyguze', 'ipakizo', 'onydo', 'ixete', 'sesel', 'xaxol', 'pydiqixah', 'ijyhi', 'mykyxov', 'vilol', 'ufy', 'dyrosyt', 'itetimi', 'cokysysiq', 'vecad', 'qef', 'olaxaviha', 'upu', 'kud', 'ywure', 'toj', 'tud', 'yra', 'witacet', 'imuhawa', 'afumywy', 'edi', 'qakideq', 'tohorynic', 'ytycyga', 'mytaquw', 'adadi', 'xev', 'cin', 'kehekyv', 'idujena', 'taheduxit', 'edicu', 'nisam', 'dobar', 'zyxepod', 'cyt', 'avehyvu', 'apozowowe', 'ciliw', 'uzonecafe', 'evasina', 'vituw', 'mycyr', 'yhume', 'okevyle', 'syv', 'eviti', 'oqeri', 'faj', 'ici', 'caxybyf', 'qev', 'epabevoqy', 'xaqeqyv', 'vuc', 'avaquludu', 'bin', 'iryharo', 'qogocif', 'aqodify', 'eroryxe', 'jedyx', 'ref', 'ziwador', 'dygaryt', 'ofo', 'fiquhocec', 'nav', 'favam', 'yvyso', 'mozodyjal', 'lur', 'kobepocon', 'owupicifu', 'saf', 'qyvin', 'kokatymuw', 'xog', 'iry', 'pew', 'dekoqyl', 'akynole')

        for i in self.max_cesty:
            if i != a and i != b and i != c:
                yield i
        # yield from self.max_cesty


if __name__ == '__main__':
    g = Graph('subor1.txt')
    # print(g.vrcholy)
    # print('vertices =', g.vertices())
    # for v1, v2 in ('mo', 'ub'), ('er', 'ub'), ('er', ' mo'):
    #     print(f'get_edge({v1!r}, {v2!r}) = {g.get_edge(v1, v2)!r}')
    riesenie = g.solve('mo')
    # print('riesenie =', riesenie)
    print(*riesenie, sep='\n')
    # for i in riesenie:
    #     print(len(i))
