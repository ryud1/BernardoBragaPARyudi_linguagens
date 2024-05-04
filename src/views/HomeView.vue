<template>
  <div class="container">
    <input id="input" placeholder="digite o codigo aqui: " class="Input">
    <div class="boxButton">
      <button @click=" this.clear()">Limpar</button>
      <button @click=" this.main()">Analisar</button>
    </div>
    <textarea name="results" id="results"></textarea>
  </div>
</template>

<script>
import HelloWorld from '@/components/HelloWorld.vue'
import { routeLocationKey } from 'vue-router'

export default {
  name: 'HomeView',
  components: {
    HelloWorld
  },
  data() {
    return {
      alfabeto: ['a', 'b', 'c', 'd', 'e'],
      VALID: 'sentença válida:',
      aritimetic: 'operador aritmético',
      sentencaInvalida: 'ERRO => sentença inválida',
      simbuloInvalido: 'ERRO => símbolo(s) inválido(s)',
      aritimeticOperators: ['+', '-', '/', '*'],
      separadores: ['+', '-', '/', '*', '$', ' '],


      tabelaT: [
    //     A|  B|  C|  D|  E| Er
  /* 0*/[10, 10, 6, 9, 10, 10],
  /* 1*/[10, 10, 10, 9, 10, 10],
  /* 2*/[3, 10, 0, 7, 10, 10],
  /* 3*/[10, 4, 10, 10, 10, 10],
  /* 4*/[5, 10, 10, 10, 10, 10],
  /* 5*/[10, 2, 10, 10, 10, 10],
  /* 6*/[10, 10, 0, 7, 10, 10],
  /* 7*/[10, 10, 10, 10, 1, 10],
  /* 8*/[10, 10, 10, 7, 10, 10],
  /* 9*/[10, 10, 10, 10, 8, 10],
  /*10*/[10, 10, 10, 10, 10, 10],
      ],
      EF: [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
    };
  },
  methods: {
    indiceSimbolo: function (simbolo) {
      if (simbolo == 'a') return 0
      else if (simbolo == 'b') return 1
      else if (simbolo == 'c') return 2
      else if (simbolo == 'd') return 3
      else if (simbolo == 'e') return 4
      else return 5
    },
    getSentencas: function (token) {
      let sentencas = [];
      let sentenca = '';

      for (const element of token) {
        if (this.separadores.includes(element)) {
          sentenca += element;
          sentencas.push(sentenca);
          sentenca = '';
        } else {
          sentenca += element
        }
      }
      return sentencas;
    },
    inAlfhabeth: function (sentenca) {
      sentenca = sentenca.trim();
      for (let i = 0; i <= sentenca.length - 1; i++) {
        if (sentenca[i] !== '$') {
          if (!this.alfabeto.includes(sentenca[i])) {
            return false;
          }
        }
      }
      return true;
    },
    generic: function (sentencas) {
      const results = document.getElementById('results');
      let estado = 2;

      for (const element of sentencas) {
        if (!this.inAlfhabeth(element)) {
          let aritmethicSimbol = false;
          let invalidSimbol = false;

          console.log('ta no else');
          console.log(element);

          for (let i = 0; i < element.length; i++) {
            console.log('bernardo');
            console.log("TESTEEE", this.aritimeticOperators.includes(element[i]));

            if (this.aritimeticOperators.includes(element[i])) {
              console.log('simbulo: ', element[i]);
              aritmethicSimbol = true;
            } else if (element[i] !== ' ') {
              invalidSimbol = true;
              break;
            }
          }
          console.log(aritmethicSimbol, invalidSimbol);

          if (aritmethicSimbol && !invalidSimbol) {
            results.value += `${this.aritimetic} ${element}\n`;
          } else if (invalidSimbol) {
            results.value += `${this.simbuloInvalido} ${element}\n`;
          } else {
            results.value += `${this.sentencaInvalida} ${element}\n`;
          }
        } else {
          // console.log('ta no if');
          // console.log(element);

          for (let i = 0; i < element.length - 1; i++) {
            let indice = this.indiceSimbolo(element[i]);
            estado = this.tabelaT[estado][indice];
          }
          console.log(estado);
          if (this.EF[estado] === 1) {

            results.value += `${this.VALID} ${element}\n`; 
          } else {
            results.value += `${this.sentencaInvalida} ${element}\n`;
          }

          estado = 2;
        }
      }
    },

    separaOperadores: function (array) {

      const regex = /([-+*/])$/;

      const novoArray = array
        .map(function (element) {
          let match = element.match(regex);
          if (match) {
            return [element.slice(0, -1), match[1]];
          } else {
            return [element];
          }
        })
        .flat()
        .filter(function (element) {
          // Remove elementos vazios ou com espaços
          return element.trim() !== "";
        });
      return novoArray;
    },

    main: function () {

      console.clear();
      const input = document.getElementById('input');
      // const results = document.getElementById('results');
      let toke = input.value;
      const token = toke + "$";
      const sentencas = this.getSentencas(token);
      console.log("Eduardo:", token);
      console.log("Eduardo", sentencas)
      console.log("Resultado", this.separaOperadores(sentencas));
      this.generic(this.separaOperadores(sentencas));

    },
    clear: function () {
      document.getElementById('input').value = '';
      document.getElementById('results').value = '';
    },
  },

}
</script>

<style scoped>
.container {
  display: flex;
  flex-direction: column;
  flex-wrap: nowrap;
  align-content: center;
  align-items: center;
  justify-content: center;
}

#results {
  width: 100%;
  min-height: 400px;
  background-color: rgb(251, 218, 175);
  margin-top: 10px;
}

.Input {
  width: 400px;
  height: 50px;
  border-radius: 20px;
  border: 2px solid rgb(68, 48, 48);
  font: rgb(0, 0, 0);
  background-color: rgb(251, 218, 175);
  margin-bottom: 10px;
}
</style>